#include "DX12SceneViewport.h"      

 namespace XYBEngine
 {
    DX12SceneViewport::DX12SceneViewport(QWidget* parent)
        : QWidget(parent)
    { 
        setAttribute(Qt::WA_NativeWindow);
        setAttribute(Qt::WA_PaintOnScreen); 
        setAttribute(Qt::WA_NoSystemBackground);
        setFocusPolicy(Qt::StrongFocus);

        if(!m_isInit)
        {
            InitDX12();
            m_isInit = true;
        }

        if(m_isInit==true){ 
            m_timer = new QTimer(this);
            connect(m_timer, &QTimer::timeout, this, &DX12SceneViewport::FrameRender);
            m_timer->start(16);
        }
    }

    DX12SceneViewport::~DX12SceneViewport()
    { 
    } 

    bool DX12SceneViewport::CheckFailed(HRESULT hr, const char* message)
    {
        if(FAILED(hr)){
            XYB_LOG_ERROR(message);
            m_timer->stop();
            delete m_timer;
            m_timer = nullptr;
            m_isInit = false;
            return false;
        }
        return true;
    }

    QPaintEngine* DX12SceneViewport::paintEngine() const
    {
        return nullptr;
    } 

    void DX12SceneViewport::showEvent(QShowEvent* event)
    {
        QWidget::showEvent(event);

        if(!m_isInit){
            InitDX12();
            m_isInit = true;
        }
    }

    void DX12SceneViewport::resizeEvent(QResizeEvent* event)
    {
        QWidget::resizeEvent(event);
    }
    
    void DX12SceneViewport::InitDX12()
    {
        HWND hwnd = reinterpret_cast<HWND>(winId());
        
    }

    void DX12SceneViewport::FrameRender()
    {
        HWND hwnd = reinterpret_cast<HWND>(winId());
        UINT dxgiFactoryFlags = 0;

        ComPtr<ID3D12Debug> debugController;
        if(SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController)))){
            debugController->EnableDebugLayer(); 
            dxgiFactoryFlags |= DXGI_CREATE_FACTORY_DEBUG;
        }

        HRESULT hr = D3D12CreateDevice(
            nullptr, 
            D3D_FEATURE_LEVEL_11_0, 
            IID_PPV_ARGS(m_device.GetAddressOf())
        );
        if(!CheckFailed(hr, "Failed to create D3D12 device")){
            return;
        }

        hr = CreateDXGIFactory2(
            dxgiFactoryFlags, 
            IID_PPV_ARGS(m_factory.GetAddressOf())
        );
        if(!CheckFailed(hr, "Failed to create DXGI factory")){  
            return;
        }

        D3D12_COMMAND_QUEUE_DESC queueDesc = {};
        queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT; 
        queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE; 

        hr = m_device->CreateCommandQueue(
            &queueDesc, 
            IID_PPV_ARGS(m_commandQueue.GetAddressOf())
        );
        if(!CheckFailed(hr, "Failed to create D3D12 command queue")){ 
            return;
        }

        DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {};
        swapChainDesc.BufferCount = 2;
        swapChainDesc.Width = width();
        swapChainDesc.Height = height();
        swapChainDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        swapChainDesc.SampleDesc.Count = 1;
        swapChainDesc.SampleDesc.Quality = 0;
        swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
        swapChainDesc.AlphaMode = DXGI_ALPHA_MODE_UNSPECIFIED;
        swapChainDesc.Scaling = DXGI_SCALING_STRETCH;
        swapChainDesc.Stereo = FALSE;
        swapChainDesc.Flags = 0;

        ComPtr<IDXGISwapChain1> swapChain;
         hr = m_factory->CreateSwapChainForHwnd(
            m_commandQueue.Get(),
            hwnd,
            &swapChainDesc,
            nullptr,
            nullptr,
            &swapChain
        );
        if(!CheckFailed(hr, "Failed to create D3D12 swap chain")){
            return;
        }


        hr = m_device->CreateCommandAllocator(
            D3D12_COMMAND_LIST_TYPE_DIRECT,
             IID_PPV_ARGS(m_commandAllocator.GetAddressOf())
            );
        if(!CheckFailed(hr, "Failed to create D3D12 command allocator")){
            return;
        }



    }
 }