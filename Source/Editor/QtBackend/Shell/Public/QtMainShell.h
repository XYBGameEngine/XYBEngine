// Copyright XYBEngine. All Rights Reserved.
//
// QtMainWindow.h - 编辑器主窗口 Qt 实现
//
// 模块：Editor / QtBackend / MainWindow
// 职责：IEditorWindow 的主窗口实现，布局由 QtMainWindow.ui 定义。

#ifndef QTMAINSHELL_H
#define QTMAINSHELL_H

#include "IEditorShell.h"
#include <QMainWindow>

namespace Ui {
class QtMainShell;
}

namespace XYBEngine
{
    /**
     * Qt 编辑器主 Shell。
     *
     * 多重继承 QMainWindow 与 IEditorShell，启动时由 EditorLauncher 注册并 Show。
     */
    class XYB_API QtMainShell : public QMainWindow, public IEditorShell
    {
        Q_OBJECT

    public:
        explicit QtMainShell(QWidget *parent = nullptr);
        ~QtMainShell();

        void Initialize() override;
        void Show() override;
        void Hide() override;
        void Close() override;
        void AddPanel(const String& defaultArea, SharedPtr<IEditorPanel> panel) override;
        void TogglePanel(const String& panelId) override;

    private:
        Ui::QtMainShell *ui;
    };
 
}


#endif // QTMAINSHELL_H
