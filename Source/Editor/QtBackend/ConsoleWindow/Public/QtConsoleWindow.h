// Copyright XYBEngine. All Rights Reserved.
//
// QtConsoleWindow.h - 控制台 Qt 控件
//
// 模块：Editor / QtBackend / ConsoleWindow
// 职责：控制台面板的 Qt 实现，布局由 QtConsoleWindow.ui 定义。

#ifndef QTCONSOLEWINDOW_H
#define QTCONSOLEWINDOW_H

#include <QWidget>
#include "IEditorWindow.h"
#include "Log.h"



namespace Ui {
class QtConsoleWindow;
}

namespace XYBEngine
{
    /** Qt 控制台窗口，实现 IEditorWindow 接口，布局由 QtConsoleWindow.ui 定义 */
    class QtConsoleWindow : public QWidget, public IEditorWindow
    {
        Q_OBJECT

    public:
        explicit QtConsoleWindow(QWidget *parent = nullptr);
        ~QtConsoleWindow();

        void Show() override;

        void Hide() override;

        void Close() override;

    private:
        Ui::QtConsoleWindow *ui;
    };

    /** 将 QtConsoleWindow 注册到 EditorWindowFactory，由 EditorLauncher 调用 */
    void QtConsoleWindowResiter();
}

#endif // QTCONSOLEWINDOW_H
