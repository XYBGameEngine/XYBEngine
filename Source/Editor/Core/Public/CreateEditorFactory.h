#ifndef CREATEEDITERRUNTIME_H
#define CREATEEDITERRUNTIME_H

#include "IEditorFactory.h" 
#include "Core.h"

namespace XYBEngine
{   
    enum class EditorApplicationBackend
    {
        Qt,
        None
    };
    XYB_API SharedPtr<IEditorFactory> CreateEditorFactory(EditorApplicationBackend backend);
}
#endif // CREATEEDITERRUNTIME_H