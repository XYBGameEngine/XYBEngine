#ifndef CONSOLEWINDOW_H
#define CONSOLEWINDOW_H

#include "Core.h"
#include "IEditorWindow.h"

namespace XYBEngine
{
    class XYB_API ConsoleWindow : public IEditorWindow
    {
    public: 
        void Show() override;
        void Hide() override;
        void Close() override; 
    };
}
#endif // CONSOLEWINDOW_H