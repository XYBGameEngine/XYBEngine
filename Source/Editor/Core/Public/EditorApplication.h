#ifndef EDITORAPPLICATION_H
#define EDITORAPPLICATION_H

#include "Core.h"

namespace XYBEngine
{
    class XYB_API EditorApplication
    {
    public:
        EditorApplication();
    
        void Init();
        void Tick();
        void Shutdown();
    };
}

#endif // EDITORAPPLICATION_H