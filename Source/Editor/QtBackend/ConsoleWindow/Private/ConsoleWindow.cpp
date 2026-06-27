#include "ConsoleWindow.h"
#include "QtConsoleWindow.h" 

namespace XYBEngine
{
    namespace
    {
        UniquePtr<QtConsoleWindow> g_consoleWindow; 
    }
    void ConsoleWindow::Initialize(int argc, char** argv)
    {
    }
    void ConsoleWindow::ShowWindow()
    {
        g_consoleWindow = MakeUnique<QtConsoleWindow>();
        g_consoleWindow->show();
    }
    void ConsoleWindow::Tick()
    {
    }
    void ConsoleWindow::Shutdown()
    {
        g_consoleWindow.reset();
    }
}