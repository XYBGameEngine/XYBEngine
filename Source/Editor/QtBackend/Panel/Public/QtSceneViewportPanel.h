#ifndef QTSCENEVIEWPORTPANEL_H
#define QTSCENEVIEWPORTPANEL_H

#include <QWidget>
#include "IEditorPanel.h"
#include "Log.h"

namespace Ui {
class QtSceneViewportPanel;
}

namespace XYBEngine
{
    class DX12ViewportWindow;

    class QtSceneViewportPanel : public QWidget, public IEditorPanel
    {
        Q_OBJECT

    public:
        explicit QtSceneViewportPanel(QWidget *parent = nullptr);
        ~QtSceneViewportPanel();

        const char* GetPanelId() const override;
        void* GetNativeView() const override;
        void Show() override;
        void Hide() override;
        void Close() override;

    private:
        Ui::QtSceneViewportPanel *ui;
        DX12ViewportWindow* m_viewportWindow = nullptr;
    };

    void QtSceneViewportPanelResiter();
}

#endif // QTSCENEVIEWPORTPANEL_H
