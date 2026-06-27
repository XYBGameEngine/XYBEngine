#ifndef IEDITORWINDOW_H
#define IEDITORWINDOW_H

#include "Core.h"

namespace XYBEngine
{
    class XYB_API IEditorWindow
    {
    public:
        virtual ~IEditorWindow() = default;
         
        virtual void Show() = 0;
        virtual void Hide() = 0;
        virtual void Close() = 0; 
    };
}
#endif // IEDITORWINDOW_H