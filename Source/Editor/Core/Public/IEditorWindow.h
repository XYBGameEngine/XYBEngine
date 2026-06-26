#ifndef IEDITORWINDOW_H
#define IEDITORWINDOW_H

#include "Core.h"

namespace XYBEngine
{
    class XYB_API IEditorWindow
    {
    public:
        virtual ~IEditorWindow() = default;
        
        virtual void ShowWindow() = 0;
    };
}
#endif // IEDITORWINDOW_H