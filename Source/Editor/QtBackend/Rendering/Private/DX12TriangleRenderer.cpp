// Copyright XYBEngine. All Rights Reserved.
//
// DX12TriangleRenderer.cpp - 最小 DX12 三角形渲染器实现

#include "DX12TriangleRenderer.h"
#include "Log.h"

#ifdef _WIN32
#include <d3dcompiler.h>
#include <cstdio>
#include <cstring>
#include <stdexcept>

namespace XYBEngine
{
    namespace
    {
        void ThrowIfFailed(HRESULT hr, const char* message)
        {
            if (FAILED(hr))
            {
                XYB_LOG_ERROR(message);
                throw std::runtime_error(message);
            }
        }

        Microsoft::WRL::ComPtr<ID3DBlob> CompileShader(const char* source, const char* entry, const char* target)
        {
            Microsoft::WRL::ComPtr<ID3DBlob> shader;
            Microsoft::WRL::ComPtr<ID3DBlob> errors;
            const HRESULT hr = D3DCompile(
                source,
                strlen(source),
                nullptr,
                nullptr,
                nullptr,
                entry,
                target,
                D3DCOMPILE_OPTIMIZATION_LEVEL3,
                0,
                &shader,
                &errors);

            if (FAILED(hr))
            {
                if (errors)
                {
                    XYB_LOG_ERROR(static_cast<const char*>(errors->GetBufferPointer()));
                }
                ThrowIfFailed(hr, "Shader compilation failed");
            }

            return shader;
        }

        bool ResolveClientSize(HWND hwnd, uint32& width, uint32& height)
        {
            if (hwnd == nullptr)
            {
                return width > 0 && height > 0;
            }

            RECT clientRect = {};
            if (!GetClientRect(hwnd, &clientRect))
            {
                return width > 0 && height > 0;
            }

            const LONG clientWidth = clientRect.right - clientRect.left;
            const LONG clientHeight = clientRect.bottom - clientRect.top;
            if (clientWidth <= 0 || clientHeight <= 0)
            {
                return false;
            }

            width = static_cast<uint32>(clientWidth);
            height = static_cast<uint32>(clientHeight);
            return true;
        }
    }

    DX12TriangleRenderer::~DX12TriangleRenderer()
    {
        Shutdown();
    }

    bool DX12TriangleRenderer::Initialize(HWND hwnd, uint32 width, uint32 height)
    {
        if (m_initialized || hwnd == nullptr || width == 0 || height == 0)
        {
            return false;
        }

        m_hwnd = hwnd;
        if (!ResolveClientSize(hwnd, width, height))
        {
            return false;
        }

        m_width = width;
        m_height = height;

        try
        {
            if (!CreateDevice())
            {
                return false;
            }

            if (!CreateSwapChain(hwnd, width, height))
            {
                return false;
            }

            if (!CreateRenderTargets())
            {
                return false;
            }

            if (!CreatePipeline())
            {
                return false;
            }

            if (!CreateVertexBuffer())
            {
                return false;
            }

            for (uint32 i = 0; i < FrameCount; ++i)
            {
                ThrowIfFailed(
                    m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_commandAllocators[i])),
                    "Failed to create command allocator");
            }

            ThrowIfFailed(
                m_device->CreateCommandList(
                    0,
                    D3D12_COMMAND_LIST_TYPE_DIRECT,
                    m_commandAllocators[0].Get(),
                    nullptr,
                    IID_PPV_ARGS(&m_commandList)),
                "Failed to create command list");
            m_commandList->Close();

            ThrowIfFailed(m_device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_fence)), "Failed to create fence");
            m_fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
            if (m_fenceEvent == nullptr)
            {
                XYB_LOG_ERROR("Failed to create fence event");
                return false;
            }

            for (uint32 i = 0; i < FrameCount; ++i)
            {
                m_fenceValues[i] = 0;
            }

            m_initialized = true;
            XYB_LOG_INFO("DX12 triangle renderer initialized");
            return true;
        }
        catch (const std::exception&)
        {
            Shutdown();
            return false;
        }
    }

    bool DX12TriangleRenderer::GetClientSize(uint32& width, uint32& height) const
    {
        return ResolveClientSize(m_hwnd, width, height);
    }

    bool DX12TriangleRenderer::NeedsSwapChainResize() const
    {
        if (!m_initialized)
        {
            return false;
        }

        uint32 clientWidth = 0;
        uint32 clientHeight = 0;
        if (!GetClientSize(clientWidth, clientHeight))
        {
            return false;
        }

        return clientWidth != m_width || clientHeight != m_height;
    }

    bool DX12TriangleRenderer::Resize(uint32 width, uint32 height)
    {
        if (!m_initialized || width == 0 || height == 0)
        {
            return false;
        }

        if (!ResolveClientSize(m_hwnd, width, height))
        {
            return false;
        }

        if (width == m_width && height == m_height)
        {
            return true;
        }

        const uint32 oldWidth = m_width;
        const uint32 oldHeight = m_height;

        try
        {
            WaitForGpu();

            for (uint32 i = 0; i < FrameCount; ++i)
            {
                m_renderTargets[i].Reset();
            }
            m_rtvHeap.Reset();

            if (!ResizeSwapChain(width, height))
            {
                if (!m_initialized)
                {
                    return false;
                }

                if (oldWidth > 0 && oldHeight > 0)
                {
                    if (!ResizeSwapChain(oldWidth, oldHeight))
                    {
                        return false;
                    }

                    m_width = oldWidth;
                    m_height = oldHeight;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                m_width = width;
                m_height = height;
            }

            m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();

            const uint64 completedFenceValue = m_fence->GetCompletedValue();
            for (uint32 i = 0; i < FrameCount; ++i)
            {
                m_fenceValues[i] = completedFenceValue;
            }

            if (!CreateRenderTargets())
            {
                XYB_LOG_ERROR("Failed to recreate render targets after resize");
                return false;
            }

            return true;
        }
        catch (const std::exception&)
        {
            XYB_LOG_ERROR("DX12 viewport resize failed");
            return false;
        }
    }

    void DX12TriangleRenderer::Render()
    {
        if (!m_initialized || NeedsSwapChainResize())
        {
            return;
        }

        try
        {
            m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();

            if (m_renderTargets[m_frameIndex] == nullptr)
            {
                return;
            }

            if (m_fence->GetCompletedValue() < m_fenceValues[m_frameIndex])
            {
                ThrowIfFailed(
                    m_fence->SetEventOnCompletion(m_fenceValues[m_frameIndex], m_fenceEvent),
                    "Failed to set fence event before rendering");
                WaitForSingleObject(m_fenceEvent, INFINITE);
            }

            ThrowIfFailed(m_commandAllocators[m_frameIndex]->Reset(), "Failed to reset command allocator");
            ThrowIfFailed(m_commandList->Reset(m_commandAllocators[m_frameIndex].Get(), m_pipelineState.Get()), "Failed to reset command list");

            D3D12_RESOURCE_BARRIER barrier = {};
            barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
            barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
            barrier.Transition.pResource = m_renderTargets[m_frameIndex].Get();
            barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
            barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;
            barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
            m_commandList->ResourceBarrier(1, &barrier);

            const float clearColor[] = {0.08f, 0.08f, 0.10f, 1.0f};
            const D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle = {
                m_rtvHeap->GetCPUDescriptorHandleForHeapStart().ptr + static_cast<SIZE_T>(m_frameIndex) * m_rtvDescriptorSize};
            m_commandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);
            m_commandList->OMSetRenderTargets(1, &rtvHandle, FALSE, nullptr);

            D3D12_VIEWPORT viewport = {};
            viewport.Width = static_cast<float>(m_width);
            viewport.Height = static_cast<float>(m_height);
            viewport.MaxDepth = 1.0f;
            D3D12_RECT scissor = {0, 0, static_cast<LONG>(m_width), static_cast<LONG>(m_height)};
            m_commandList->RSSetViewports(1, &viewport);
            m_commandList->RSSetScissorRects(1, &scissor);

            m_commandList->SetGraphicsRootSignature(m_rootSignature.Get());
            m_commandList->SetPipelineState(m_pipelineState.Get());
            m_commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
            m_commandList->IASetVertexBuffers(0, 1, &m_vertexBufferView);
            m_commandList->DrawInstanced(3, 1, 0, 0);

            barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
            barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
            m_commandList->ResourceBarrier(1, &barrier);

            ThrowIfFailed(m_commandList->Close(), "Failed to close command list");

            ID3D12CommandList* commandLists[] = {m_commandList.Get()};
            m_commandQueue->ExecuteCommandLists(1, commandLists);

            const HRESULT presentHr = m_swapChain->Present(0, 0);
            if (presentHr == DXGI_ERROR_DEVICE_REMOVED || presentHr == DXGI_ERROR_DEVICE_RESET)
            {
                XYB_LOG_ERROR("DX12 device lost during present");
                Shutdown();
                return;
            }

            if (FAILED(presentHr))
            {
                XYB_LOG_ERROR("Failed to present swap chain");
                return;
            }

            MoveToNextFrame();
        }
        catch (const std::exception&)
        {
            XYB_LOG_ERROR("DX12 viewport render failed");
        }
    }

    void DX12TriangleRenderer::Shutdown()
    {
        if (!m_initialized && m_device == nullptr)
        {
            return;
        }

        try
        {
            WaitForGpu();
        }
        catch (const std::exception&)
        {
            XYB_LOG_ERROR("DX12 viewport shutdown wait failed");
        }

        if (m_fenceEvent != nullptr)
        {
            CloseHandle(m_fenceEvent);
            m_fenceEvent = nullptr;
        }

        m_vertexBuffer.Reset();
        m_pipelineState.Reset();
        m_rootSignature.Reset();
        m_commandList.Reset();

        for (uint32 i = 0; i < FrameCount; ++i)
        {
            m_commandAllocators[i].Reset();
            m_renderTargets[i].Reset();
        }

        m_rtvHeap.Reset();
        m_swapChain.Reset();
        m_commandQueue.Reset();
        m_device.Reset();
        m_factory.Reset();

        m_initialized = false;
        m_hwnd = nullptr;
    }

    bool DX12TriangleRenderer::CreateDevice()
    {
#if defined(_DEBUG)
        Microsoft::WRL::ComPtr<ID3D12Debug> debugController;
        if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController))))
        {
            debugController->EnableDebugLayer();
        }
#endif

        ThrowIfFailed(CreateDXGIFactory1(IID_PPV_ARGS(&m_factory)), "Failed to create DXGI factory");

        Microsoft::WRL::ComPtr<IDXGIAdapter1> adapter;
        for (UINT adapterIndex = 0; m_factory->EnumAdapters1(adapterIndex, &adapter) != DXGI_ERROR_NOT_FOUND; ++adapterIndex)
        {
            DXGI_ADAPTER_DESC1 desc = {};
            adapter->GetDesc1(&desc);
            if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
            {
                continue;
            }

            if (SUCCEEDED(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&m_device))))
            {
                break;
            }
        }

        if (m_device == nullptr)
        {
            ThrowIfFailed(D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&m_device)), "Failed to create D3D12 device");
        }

        D3D12_COMMAND_QUEUE_DESC queueDesc = {};
        queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
        ThrowIfFailed(m_device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&m_commandQueue)), "Failed to create command queue");
        return true;
    }

    bool DX12TriangleRenderer::CreateSwapChain(HWND hwnd, uint32 width, uint32 height)
    {
        DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {};
        swapChainDesc.Width = width;
        swapChainDesc.Height = height;
        swapChainDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        swapChainDesc.SampleDesc.Count = 1;
        swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        swapChainDesc.BufferCount = FrameCount;
        swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;

        Microsoft::WRL::ComPtr<IDXGISwapChain1> swapChain;
        ThrowIfFailed(
            m_factory->CreateSwapChainForHwnd(
                m_commandQueue.Get(),
                hwnd,
                &swapChainDesc,
                nullptr,
                nullptr,
                &swapChain),
            "Failed to create swap chain");

        ThrowIfFailed(m_factory->MakeWindowAssociation(hwnd, DXGI_MWA_NO_ALT_ENTER), "Failed to disable Alt+Enter");
        ThrowIfFailed(swapChain.As(&m_swapChain), "Failed to query IDXGISwapChain3");
        m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();
        return true;
    }

    bool DX12TriangleRenderer::ResizeSwapChain(uint32 width, uint32 height)
    {
        if (m_swapChain == nullptr)
        {
            return false;
        }

        const HRESULT hr = m_swapChain->ResizeBuffers(
            FrameCount,
            width,
            height,
            DXGI_FORMAT_R8G8B8A8_UNORM,
            0);

        if (FAILED(hr))
        {
            char message[128] = {};
            std::snprintf(
                message,
                sizeof(message),
                "Failed to resize swap chain (0x%08X) to %ux%u",
                static_cast<unsigned>(hr),
                width,
                height);
            XYB_LOG_ERROR(message);

            if (hr == DXGI_ERROR_DEVICE_REMOVED || hr == DXGI_ERROR_DEVICE_RESET)
            {
                Shutdown();
            }

            return false;
        }

        return true;
    }

    bool DX12TriangleRenderer::CreateRenderTargets()
    {
        D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc = {};
        rtvHeapDesc.NumDescriptors = FrameCount;
        rtvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
        rtvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
        ThrowIfFailed(m_device->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(&m_rtvHeap)), "Failed to create RTV heap");

        m_rtvDescriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
        D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle = m_rtvHeap->GetCPUDescriptorHandleForHeapStart();

        for (uint32 i = 0; i < FrameCount; ++i)
        {
            ThrowIfFailed(m_swapChain->GetBuffer(i, IID_PPV_ARGS(&m_renderTargets[i])), "Failed to get swap chain buffer");
            m_device->CreateRenderTargetView(m_renderTargets[i].Get(), nullptr, rtvHandle);
            rtvHandle.ptr += m_rtvDescriptorSize;
        }

        return true;
    }

    bool DX12TriangleRenderer::CreatePipeline()
    {
        D3D12_ROOT_SIGNATURE_DESC rootSignatureDesc = {};
        rootSignatureDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;
        Microsoft::WRL::ComPtr<ID3DBlob> signature;
        Microsoft::WRL::ComPtr<ID3DBlob> error;
        ThrowIfFailed(
            D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &signature, &error),
            "Failed to serialize root signature");
        ThrowIfFailed(
            m_device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&m_rootSignature)),
            "Failed to create root signature");

        static const char* kVertexShader = R"(
            struct VSInput
            {
                float3 pos : POSITION;
                float3 col : COLOR;
            };

            struct PSInput
            {
                float4 pos : SV_POSITION;
                float3 col : COLOR;
            };

            PSInput main(VSInput input)
            {
                PSInput output;
                output.pos = float4(input.pos, 1.0f);
                output.col = input.col;
                return output;
            }
        )";

        static const char* kPixelShader = R"(
            struct PSInput
            {
                float4 pos : SV_POSITION;
                float3 col : COLOR;
            };

            float4 main(PSInput input) : SV_TARGET
            {
                return float4(input.col, 1.0f);
            }
        )";

        const auto vertexShader = CompileShader(kVertexShader, "main", "vs_5_0");
        const auto pixelShader = CompileShader(kPixelShader, "main", "ps_5_0");

        D3D12_INPUT_ELEMENT_DESC inputElements[] = {
            {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0},
            {"COLOR", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0},
        };

        D3D12_GRAPHICS_PIPELINE_STATE_DESC pipelineDesc = {};
        pipelineDesc.pRootSignature = m_rootSignature.Get();
        pipelineDesc.VS = {vertexShader->GetBufferPointer(), vertexShader->GetBufferSize()};
        pipelineDesc.PS = {pixelShader->GetBufferPointer(), pixelShader->GetBufferSize()};
        pipelineDesc.InputLayout = {inputElements, static_cast<UINT>(sizeof(inputElements) / sizeof(inputElements[0]))};
        D3D12_RASTERIZER_DESC rasterizerDesc = {};
        rasterizerDesc.FillMode = D3D12_FILL_MODE_SOLID;
        rasterizerDesc.CullMode = D3D12_CULL_MODE_BACK;
        rasterizerDesc.FrontCounterClockwise = FALSE;
        rasterizerDesc.DepthBias = D3D12_DEFAULT_DEPTH_BIAS;
        rasterizerDesc.DepthBiasClamp = D3D12_DEFAULT_DEPTH_BIAS_CLAMP;
        rasterizerDesc.SlopeScaledDepthBias = D3D12_DEFAULT_SLOPE_SCALED_DEPTH_BIAS;
        rasterizerDesc.DepthClipEnable = TRUE;
        rasterizerDesc.MultisampleEnable = FALSE;
        rasterizerDesc.AntialiasedLineEnable = FALSE;
        rasterizerDesc.ForcedSampleCount = 0;
        rasterizerDesc.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;
        pipelineDesc.RasterizerState = rasterizerDesc;

        D3D12_BLEND_DESC blendDesc = {};
        blendDesc.AlphaToCoverageEnable = FALSE;
        blendDesc.IndependentBlendEnable = FALSE;
        const D3D12_RENDER_TARGET_BLEND_DESC defaultRenderTargetBlendDesc = {
            FALSE,
            FALSE,
            D3D12_BLEND_ONE,
            D3D12_BLEND_ZERO,
            D3D12_BLEND_OP_ADD,
            D3D12_BLEND_ONE,
            D3D12_BLEND_ZERO,
            D3D12_BLEND_OP_ADD,
            D3D12_LOGIC_OP_NOOP,
            D3D12_COLOR_WRITE_ENABLE_ALL,
        };
        for (UINT i = 0; i < D3D12_SIMULTANEOUS_RENDER_TARGET_COUNT; ++i)
        {
            blendDesc.RenderTarget[i] = defaultRenderTargetBlendDesc;
        }
        pipelineDesc.BlendState = blendDesc;
        pipelineDesc.DepthStencilState.DepthEnable = FALSE;
        pipelineDesc.DepthStencilState.StencilEnable = FALSE;
        pipelineDesc.SampleMask = UINT_MAX;
        pipelineDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
        pipelineDesc.NumRenderTargets = 1;
        pipelineDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
        pipelineDesc.SampleDesc.Count = 1;

        ThrowIfFailed(m_device->CreateGraphicsPipelineState(&pipelineDesc, IID_PPV_ARGS(&m_pipelineState)), "Failed to create pipeline state");
        return true;
    }

    bool DX12TriangleRenderer::CreateVertexBuffer()
    {
        const Vertex triangleVertices[] = {
            {{0.0f, 0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}},
            {{0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}},
            {{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}},
        };

        const UINT vertexBufferSize = sizeof(triangleVertices);

        D3D12_HEAP_PROPERTIES uploadHeapProps = {};
        uploadHeapProps.Type = D3D12_HEAP_TYPE_UPLOAD;
        D3D12_RESOURCE_DESC bufferDesc = {};
        bufferDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
        bufferDesc.Width = vertexBufferSize;
        bufferDesc.Height = 1;
        bufferDesc.DepthOrArraySize = 1;
        bufferDesc.MipLevels = 1;
        bufferDesc.SampleDesc.Count = 1;
        bufferDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

        ThrowIfFailed(
            m_device->CreateCommittedResource(
                &uploadHeapProps,
                D3D12_HEAP_FLAG_NONE,
                &bufferDesc,
                D3D12_RESOURCE_STATE_GENERIC_READ,
                nullptr,
                IID_PPV_ARGS(&m_vertexBuffer)),
            "Failed to create vertex buffer");

        void* mappedData = nullptr;
        D3D12_RANGE readRange = {0, 0};
        ThrowIfFailed(m_vertexBuffer->Map(0, &readRange, &mappedData), "Failed to map vertex buffer");
        memcpy(mappedData, triangleVertices, vertexBufferSize);
        m_vertexBuffer->Unmap(0, nullptr);

        m_vertexBufferView.BufferLocation = m_vertexBuffer->GetGPUVirtualAddress();
        m_vertexBufferView.SizeInBytes = vertexBufferSize;
        m_vertexBufferView.StrideInBytes = sizeof(Vertex);
        return true;
    }

    void DX12TriangleRenderer::WaitForGpu()
    {
        if (m_commandQueue == nullptr || m_fence == nullptr || m_fenceEvent == nullptr)
        {
            return;
        }

        const uint64 fenceValue = m_fence->GetCompletedValue() + 1;
        ThrowIfFailed(m_commandQueue->Signal(m_fence.Get(), fenceValue), "Failed to signal fence during GPU wait");
        ThrowIfFailed(m_fence->SetEventOnCompletion(fenceValue, m_fenceEvent), "Failed to set fence event during GPU wait");
        WaitForSingleObject(m_fenceEvent, INFINITE);
    }

    void DX12TriangleRenderer::MoveToNextFrame()
    {
        const uint64 fenceValue = m_fenceValues[m_frameIndex] + 1;
        ThrowIfFailed(m_commandQueue->Signal(m_fence.Get(), fenceValue), "Failed to signal fence");
        m_fenceValues[m_frameIndex] = fenceValue;
    }
}
#endif
