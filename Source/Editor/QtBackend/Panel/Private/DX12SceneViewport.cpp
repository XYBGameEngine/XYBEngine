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
        UINT dxgiFactoryFlags = 0;

        ComPtr<ID3D12Debug> debugController;
        if(SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController)))){
            debugController->EnableDebugLayer(); 
            dxgiFactoryFlags |= DXGI_CREATE_FACTORY_DEBUG;
        }

        ComPtr<IDXGIFactory4> factory;

        HRESULT hr = CreateDXGIFactory2(dxgiFactoryFlags, IID_PPV_ARGS(factory.GetAddressOf()));
        if(FAILED(hr)){
            XYB_LOG_ERROR("Failed to create DXGI factory");
            return;
        } 
    }
 }