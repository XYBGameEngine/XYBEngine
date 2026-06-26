#ifndef IEDITORWINDOW_H
#define IEDITORWINDOW_H

#include "Core.h"

namespace XYBEngine
{
    class XYB_API IEditorWindow
    {
    public:
        virtual ~IEditorWindow() = default;
        
        virtual void Initialize(int argc, char** argv) = 0;
        virtual void Tick() = 0;
        virtual void Shutdown() = 0;
        virtual void ShowWindow() = 0;
    };
}
#endif // IEDITORWINDOW_H