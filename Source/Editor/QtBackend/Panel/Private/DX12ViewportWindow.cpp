#include "DX12ViewportWindow.h"

#ifdef _WIN32

#include "Log.h"

#include <QEvent>
#include <QPlatformSurfaceEvent>
#include <QResizeEvent>

namespace XYBEngine
{
    DX12ViewportWindow::DX12ViewportWindow(QWindow* parent)
        : QWindow(parent)
    {
        setMinimumSize(QSize(320, 240));
    }

    DX12ViewportWindow::~DX12ViewportWindow()
    {
        m_renderer.Shutdown();
    }

    bool DX12ViewportWindow::event(QEvent* event)
    {
        switch (event->type())
        {
        case QEvent::UpdateRequest:
            renderFrame();
            break;

        case QEvent::PlatformSurface:
            if (static_cast<QPlatformSurfaceEvent*>(event)->surfaceEventType()
                == QPlatformSurfaceEvent::SurfaceAboutToBeDestroyed)
            {
                m_renderer.Shutdown();
            }
            break;

        default:
            break;
        }

        return QWindow::event(event);
    }

    void DX12ViewportWindow::exposeEvent(QExposeEvent* event)
    {
        QWindow::exposeEvent(event);

        if (isExposed())
        {
            requestUpdate();
        }
    }

    void DX12ViewportWindow::resizeEvent(QResizeEvent* event)
    {
        QWindow::resizeEvent(event);

        if (event->size().width() <= 0 || event->size().height() <= 0)
        {
            return;
        }

        m_hasPendingResize = true;
        m_lastFailedWidth = 0;
        m_lastFailedHeight = 0;

        if (isExposed())
        {
            requestUpdate();
        }
    }

    bool DX12ViewportWindow::tryInitialize()
    {
        if (m_renderer.IsInitialized())
        {
            return true;
        }

        const uint32 w = static_cast<uint32>(width());
        const uint32 h = static_cast<uint32>(height());
        if (w == 0 || h == 0)
        {
            return false;
        }

        const auto hwnd = reinterpret_cast<HWND>(winId());
        if (!m_renderer.Initialize(hwnd, w, h))
        {
            XYB_LOG_ERROR("Failed to initialize DX12 viewport renderer");
            return false;
        }

        return true;
    }

    void DX12ViewportWindow::applyPendingResize()
    {
        if (!m_renderer.IsInitialized())
        {
            return;
        }

        if (!m_hasPendingResize && !m_renderer.NeedsSwapChainResize())
        {
            return;
        }

        uint32 width = static_cast<uint32>(QWindow::width());
        uint32 height = static_cast<uint32>(QWindow::height());
        if (!m_renderer.GetClientSize(width, height))
        {
            return;
        }

        if (width == m_renderer.GetWidth() && height == m_renderer.GetHeight())
        {
            m_hasPendingResize = false;
            m_lastFailedWidth = 0;
            m_lastFailedHeight = 0;
            return;
        }

        if (width == m_lastFailedWidth && height == m_lastFailedHeight)
        {
            return;
        }

        if (m_renderer.Resize(width, height))
        {
            m_hasPendingResize = false;
            m_lastFailedWidth = 0;
            m_lastFailedHeight = 0;
        }
        else
        {
            m_lastFailedWidth = width;
            m_lastFailedHeight = height;
        }
    }

    void DX12ViewportWindow::renderFrame()
    {
        if (!isExposed())
        {
            return;
        }

        if (!tryInitialize())
        {
            return;
        }

        applyPendingResize();

        if (m_hasPendingResize || m_renderer.NeedsSwapChainResize())
        {
            requestUpdate();
            return;
        }

        m_renderer.Render();

        // Qt 官方 RHI Window 示例：用 requestUpdate 驱动连续渲染，由平台 vsync 节流
        requestUpdate();
    }
}

#endif
