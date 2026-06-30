#include "DX12SceneViewport.h"

#include "Log.h"

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

    }
 }