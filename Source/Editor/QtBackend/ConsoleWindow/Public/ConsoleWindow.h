#ifndef CONSOLEWINDOW_H
#define CONSOLEWINDOW_H

#include "Core.h"
#include "IEditorWindow.h"
#include "QtConsoleWindow.h"

namespace XYBEngine
{
    class XYB_API ConsoleWindow : public IEditorWindow
    {
    public: 
        void ShowWindow() override;
    };
}
#endif // CONSOLEWINDOW_H