#ifndef DX12SCENEVIEWPORT_H
#define DX12SCENEVIEWPORT_H

#include "Core.h"

namespace XYBEngine
{
    class DX12SceneViewport : public QWidget
    {
        Q_OBJECT

        public:
            explicit DX12SceneViewport(QWidget* parent = nullptr);
            ~DX12SceneViewport();

        protected:
            QPaintEngine* paintEngine() const override;
            void showEvent(QShowEvent* event) override;
            void resizeEvent(QResizeEvent* event) override;
            void paintEvent(QPaintEvent* event) override;  

            void InitDX12();
            void FrameRender();
    };
}

#endif