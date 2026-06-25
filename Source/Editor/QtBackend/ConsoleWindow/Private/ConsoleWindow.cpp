#include "ConsoleWindow.h"

namespace XYBEngine
{
    void ConsoleWindow::ShowWindow()
    {
        QtConsoleWindow *window = new QtConsoleWindow();
        window->show();
    }
}