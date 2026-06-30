#include "DX12SceneViewport.h"

#include "Log.h"

 namespace XYBEngine
 {
    DX12SceneViewport::DX12SceneViewport(QWidget* parent)
        : QWidget(parent)
    {
        setMinimumSize(320, 240);
        setAttribute(Qt::WA_NativeWindow);
        setAttribute(Qt::WA_PaintOnScreen);
        setAttribute(Qt::WA_OpaquePaintEvent);
        setAttribute(Qt::WA_NoSystemBackground);
        setFocusPolicy(Qt::StrongFocus);
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
        if (isVisible())
        {
            update();
        }
    }

    void DX12SceneViewport::resizeEvent(QResizeEvent* event)
    {
        QWidget::resizeEvent(event);
    }
 }