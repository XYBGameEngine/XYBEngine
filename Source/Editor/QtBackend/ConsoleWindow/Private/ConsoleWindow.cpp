// Copyright XYBEngine. All Rights Reserved.
//
// ConsoleWindow.cpp - 控制台窗口门面实现
//
// 说明：g_consoleWindow 为模块内单例，Show 时创建，Close 时销毁 Qt 控件。

#include "ConsoleWindow.h"
#include "QtConsoleWindow.h" 

namespace XYBEngine
{ 
    ConsoleWindow::~ConsoleWindow()
    {
        m_consoleWindow.reset();
    }

    void ConsoleWindow::Show()
    {
        if (!m_consoleWindow)
        {
            m_consoleWindow = MakeUnique<QtConsoleWindow>();
        } 
        m_consoleWindow->show();   
    }

    void ConsoleWindow::Hide()
    {
        if (!m_consoleWindow)
        {
            return;
        }
        m_consoleWindow->hide();
    }

    void ConsoleWindow::Close()
    {
        if (!m_consoleWindow)
        {
            return;
        }
        m_consoleWindow->close();
    } 
}