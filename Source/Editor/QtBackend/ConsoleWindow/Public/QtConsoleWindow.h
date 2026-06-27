// Copyright XYBEngine. All Rights Reserved.
//
// QtConsoleWindow.h - 控制台 Qt 控件
//
// 模块：Editor / QtBackend / ConsoleWindow
// 职责：控制台面板的 Qt 实现，布局由 QtConsoleWindow.ui 定义。

#ifndef QTCONSOLEWINDOW_H
#define QTCONSOLEWINDOW_H

#include <QWidget>
#include "QtHelper.h" 
#include "IEditorWindow.h"
#include "Log.h"

using namespace XYBEngine;

namespace Ui {
class QtConsoleWindow;
}

/** Qt 控制台窗口控件，由 ConsoleWindow 门面持有与驱动 */
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

#endif // QTCONSOLEWINDOW_H
