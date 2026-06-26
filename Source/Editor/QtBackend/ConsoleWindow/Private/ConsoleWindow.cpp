#include "ConsoleWindow.h"

namespace XYBEngine
{
    void ConsoleWindow::Initialize(int argc, char** argv)
    {
    }
    void ConsoleWindow::ShowWindow()
    {
        QtConsoleWindow *window = new QtConsoleWindow();
        window->show();
    }
    void ConsoleWindow::Tick()
    {
    }
    void ConsoleWindow::Shutdown()
    {
    }
}