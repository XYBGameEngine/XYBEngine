#ifndef CONSOLEWINDOW_H
#define CONSOLEWINDOW_H

#include "Core.h"
#include "IEditorWindow.h"

namespace XYBEngine
{
    class XYB_API ConsoleWindow : public IEditorWindow
    {
    public: 
        void Initialize(int argc, char** argv) override;
        void Tick() override;
        void Shutdown() override;
        void ShowWindow() override;
    };
}
#endif // CONSOLEWINDOW_H