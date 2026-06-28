#pragma once

#ifdef _WIN32

#include "DX12TriangleRenderer.h"

#include <QWindow>

class QExposeEvent;
class QResizeEvent;

namespace XYBEngine
{
    /** DX12 视口窗口，遵循 Qt RHI/OpenGL Window 示例的 requestUpdate 渲染循环 */
    class DX12ViewportWindow final : public QWindow
    {
    public:
        explicit DX12ViewportWindow(QWindow* parent = nullptr);
        ~DX12ViewportWindow() override;

    protected:
        bool event(QEvent* event) override;
        void exposeEvent(QExposeEvent* event) override;
        void resizeEvent(QResizeEvent* event) override;

    private:
        bool tryInitialize();
        void applyPendingResize();
        void renderFrame();

        DX12TriangleRenderer m_renderer;
        uint32 m_lastFailedWidth = 0;
        uint32 m_lastFailedHeight = 0;
        bool m_hasPendingResize = false;
    };
}

#endif
