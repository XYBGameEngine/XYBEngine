// Copyright XYBEngine. All Rights Reserved.
//
// QtConsolePanel.h - 控制台 Qt 控件
//
// 模块：Editor / QtBackend / ConsoleWindow
// 职责：控制台面板的 Qt 实现，布局由 QtConsolePanel.ui 定义。

#ifndef QTCONSOLEPANEL_H
#define QTCONSOLEPANEL_H

#include <QWidget>
#include "IEditorPanel.h"
#include "Log.h"

namespace Ui {
class QtConsolePanel;
}

namespace XYBEngine
{
    /** Qt 控制台窗口，实现 IEditorPanel 接口，布局由 QtConsolePanel.ui 定义 */
    class QtConsolePanel : public QWidget, public IEditorPanel
    {
        Q_OBJECT

    public:
        explicit QtConsolePanel(QWidget *parent = nullptr);
        ~QtConsolePanel();

        const char* GetPanelId() const override;
        void* GetNativeView() const override;

        void Show() override;
        void Hide() override;
        void Close() override;

    private:
        Ui::QtConsolePanel *ui;
    };

    /** 将 QtConsolePanel 注册到 EditorPanelRegister，由 EditorLauncher 调用 */
    void QtConsolePanelResiter(); 
}

#endif // QTCONSOLEWINDOW_H
