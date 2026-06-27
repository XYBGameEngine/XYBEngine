// Copyright XYBEngine. All Rights Reserved.
//
// ConsoleWindow.cpp - 控制台窗口门面实现
//
// 说明：g_consoleWindow 为模块内单例，Show 时创建，Close 时销毁 Qt 控件。

#include "ConsoleWindow.h"
#include "QtConsoleWindow.h" 

namespace XYBEngine
{
    namespace
    {
        /** 控制台对应的 Qt 控件实例，生命周期由 Show/Close 管理 */
        UniquePtr<QtConsoleWindow> g_consoleWindow; 
    }

    void ConsoleWindow::Show()
    {
        g_consoleWindow = MakeUnique<QtConsoleWindow>();
        g_consoleWindow->show();
    }

    void ConsoleWindow::Hide()
    {
        g_consoleWindow->hide();
    }

    void ConsoleWindow::Close()
    {
        g_consoleWindow->close();
    } 
}