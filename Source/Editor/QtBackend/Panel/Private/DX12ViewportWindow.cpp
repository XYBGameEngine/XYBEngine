#include "DX12ViewportWindow.h"

#ifdef _WIN32

#include "Log.h"

#include <QPaintEvent>
#include <QResizeEvent>
#include <QShowEvent>

namespace XYBEngine
{
    DX12ViewportWindow::DX12ViewportWindow(QWidget* parent)
        : QWidget(parent)
    {
        setMinimumSize(320, 240);
        setAttribute(Qt::WA_NativeWindow);
        setAttribute(Qt::WA_PaintOnScreen);
        setAttribute(Qt::WA_OpaquePaintEvent);
        setAttribute(Qt::WA_NoSystemBackground);
        setFocusPolicy(Qt::StrongFocus);
    }

    DX12ViewportWindow::~DX12ViewportWindow()
    {
        m_renderer.Shutdown();
    }

    QPaintEngine* DX12ViewportWindow::paintEngine() const
    {
        return nullptr;
    }

    void DX12ViewportWindow::showEvent(QShowEvent* event)
    {
        QWidget::showEvent(event);
        update();
    }

    void DX12ViewportWindow::resizeEvent(QResizeEvent* event)
    {
        QWidget::resizeEvent(event);

        if (event->size().width() <= 0 || event->size().height() <= 0)
        {
            return;
        }

        m_hasPendingResize = true;
        m_lastFailedWidth = 0;
        m_lastFailedHeight = 0;

        if (isVisible())
        {
            update();
        }
    }

    bool DX12ViewportWindow::tryInitialize()
    {
        if (m_renderer.IsInitialized())
        {
            return true;
        }

        if (!isVisible())
        {
            return false;
        }

        const WId windowId = winId();
        if (windowId == 0)
        {
            return false;
        }

        const auto hwnd = reinterpret_cast<HWND>(windowId);
        if (!IsWindow(hwnd) || !IsWindowVisible(hwnd))
        {
            return false;
        }

        uint32 width = static_cast<uint32>(QWidget::width());
        uint32 height = static_cast<uint32>(QWidget::height());

        RECT clientRect = {};
        if (GetClientRect(hwnd, &clientRect))
        {
            const LONG clientWidth = clientRect.right - clientRect.left;
            const LONG clientHeight = clientRect.bottom - clientRect.top;
            if (clientWidth > 0 && clientHeight > 0)
            {
                width = static_cast<uint32>(clientWidth);
                height = static_cast<uint32>(clientHeight);
            }
        }

        if (width == 0 || height == 0)
        {
            return false;
        }

        if (!m_renderer.Initialize(hwnd, width, height))
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

        uint32 width = static_cast<uint32>(QWidget::width());
        uint32 height = static_cast<uint32>(QWidget::height());
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
        if (!isVisible())
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
            update();
            return;
        }

        m_renderer.Render();

        if (m_renderer.IsInitialized())
        {
            update();
        }
    }

    void DX12ViewportWindow::paintEvent(QPaintEvent* event)
    {
        Q_UNUSED(event);
        renderFrame();
    }
}

#endif
