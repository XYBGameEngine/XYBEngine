#ifndef CONSOLEWINDOW_H
#define CONSOLEWINDOW_H

#include "Core.h"
#include "IConsoleWindow.h"
#include "QtConsoleWindow.h"

namespace XYBEngine
{
    class XYB_API ConsoleWindow : public IConsoleWindow
    {
    public: 
        void ShowWindow() override;
    };
}
#endif // CONSOLEWINDOW_H