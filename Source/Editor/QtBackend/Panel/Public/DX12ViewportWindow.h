#pragma once

#ifdef _WIN32

#include "DX12TriangleRenderer.h"

#include <QWidget>

class QPaintEvent;
class QResizeEvent;
class QShowEvent;

namespace XYBEngine
{
    /** DX12 视口控件，使用原生 HWND + WA_PaintOnScreen 嵌入 Qt 面板 */
    class DX12ViewportWindow final : public QWidget
    {
    public:
        explicit DX12ViewportWindow(QWidget* parent = nullptr);
        ~DX12ViewportWindow() override;

    protected:
        QPaintEngine* paintEngine() const override;
        void showEvent(QShowEvent* event) override;
        void resizeEvent(QResizeEvent* event) override;
        void paintEvent(QPaintEvent* event) override;

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
