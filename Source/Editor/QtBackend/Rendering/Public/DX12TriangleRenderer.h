// Copyright XYBEngine. All Rights Reserved.
//
// DX12TriangleRenderer.h - 最小 DX12 三角形渲染器

#pragma once

#include "Core.h"

#ifdef _WIN32
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0A00
#endif
#ifndef NTDDI_VERSION
#define NTDDI_VERSION 0x0A000000
#endif
#include <windows.h>
#include <wrl/client.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#endif

namespace XYBEngine
{
#ifdef _WIN32
    /** 在 HWND 上通过 DX12 绘制一个彩色三角形 */
    class DX12TriangleRenderer
    {
    public:
        DX12TriangleRenderer() = default;
        ~DX12TriangleRenderer();

        bool Initialize(HWND hwnd, uint32 width, uint32 height);
        void Resize(uint32 width, uint32 height);
        void Render();
        void Shutdown();

        bool IsInitialized() const { return m_initialized; }

    private:
        struct Vertex
        {
            float pos[3];
            float col[3];
        };

        static constexpr uint32 FrameCount = 2;

        bool CreateDevice();
        bool CreateSwapChain(HWND hwnd, uint32 width, uint32 height);
        bool CreateRenderTargets();
        bool CreatePipeline();
        bool CreateVertexBuffer();
        void WaitForGpu();
        void MoveToNextFrame();

        bool m_initialized = false;
        HWND m_hwnd = nullptr;
        uint32 m_width = 0;
        uint32 m_height = 0;
        uint32 m_frameIndex = 0;
        uint64 m_fenceValues[FrameCount] = {};

        Microsoft::WRL::ComPtr<IDXGIFactory4> m_factory;
        Microsoft::WRL::ComPtr<IDXGISwapChain3> m_swapChain;
        Microsoft::WRL::ComPtr<ID3D12Device> m_device;
        Microsoft::WRL::ComPtr<ID3D12CommandQueue> m_commandQueue;
        Microsoft::WRL::ComPtr<ID3D12CommandAllocator> m_commandAllocators[FrameCount];
        Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> m_commandList;
        Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_rtvHeap;
        Microsoft::WRL::ComPtr<ID3D12Resource> m_renderTargets[FrameCount];
        Microsoft::WRL::ComPtr<ID3D12RootSignature> m_rootSignature;
        Microsoft::WRL::ComPtr<ID3D12PipelineState> m_pipelineState;
        Microsoft::WRL::ComPtr<ID3D12Resource> m_vertexBuffer;
        D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView = {};
        Microsoft::WRL::ComPtr<ID3D12Fence> m_fence;
        HANDLE m_fenceEvent = nullptr;
        uint32 m_rtvDescriptorSize = 0;
    };
#endif
}
