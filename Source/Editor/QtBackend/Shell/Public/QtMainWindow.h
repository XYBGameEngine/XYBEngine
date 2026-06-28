// Copyright XYBEngine. All Rights Reserved.
//
// QtMainWindow.h - 编辑器主窗口 Qt 实现
//
// 模块：Editor / QtBackend / MainWindow
// 职责：IEditorWindow 的主窗口实现，布局由 QtMainWindow.ui 定义。

#ifndef QTMAINWINDOW_H
#define QTMAINWINDOW_H

#include "IEditorWindow.h"
#include <QMainWindow>

namespace Ui {
class QtMainWindow;
}

namespace XYBEngine
{
    /**
     * Qt 编辑器主窗口。
     *
     * 多重继承 QMainWindow 与 IEditorWindow，启动时由 EditorLauncher 注册并 Show。
     */
    class QtMainWindow : public QMainWindow, public IEditorWindow
    {
        Q_OBJECT

    public:
        explicit QtMainWindow(QWidget *parent = nullptr);
        ~QtMainWindow();

        void Show() override;
        void Hide() override;
        void Close() override;

    private:
        Ui::QtMainWindow *ui;
    };

    /** 将 QtMainWindow 注册到 EditorWindowFactory，由 EditorLauncher 调用 */
    void QtMainWindowResiter();
}


#endif // QTMAINWINDOW_H
