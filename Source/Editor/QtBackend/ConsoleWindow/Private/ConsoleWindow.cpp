#include "ConsoleWindow.h"
#include "QtConsoleWindow.h" 

namespace XYBEngine
{
    namespace
    {
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