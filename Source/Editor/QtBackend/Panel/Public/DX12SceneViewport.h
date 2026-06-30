#ifndef DX12SCENEVIEWPORT_H
#define DX12SCENEVIEWPORT_H

#include "Core.h"
#include <QWidget>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QShowEvent>
#include <QTimer>
#include <Windows.h>
#include <wrl/client.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <stdexcept>

namespace XYBEngine
{
    class DX12SceneViewport : public QWidget
    {
        Q_OBJECT
        private:
            bool m_isInit = false;
        public:
            explicit DX12SceneViewport(QWidget* parent = nullptr);
            ~DX12SceneViewport();

        protected:
            QPaintEngine* paintEngine() const override;
            void showEvent(QShowEvent* event) override;
            void resizeEvent(QResizeEvent* event) override;   

            void InitDX12();
            void FrameRender();
    };
}

#endif