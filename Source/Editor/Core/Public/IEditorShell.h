#ifndef IEDITORSHELL_H
#define IEDITORSHELL_H

#include "Core.h" 
#include "Log.h"
#include "IEditorPanel.h"

namespace XYBEngine
{
    class XYB_API IEditorShell
    {
    public:
        virtual ~IEditorShell() = default;
        
        virtual void Initialize() = 0;
        virtual void Show() = 0;
        virtual void Hide() = 0;
        virtual void Close() = 0;
        virtual void AddPanel(const String& defaultArea, SharedPtr<IEditorPanel> panel) = 0;
        virtual void TogglePanel(const String& panelId) = 0;
    };
}
#endif // IEDITORSHELL_H