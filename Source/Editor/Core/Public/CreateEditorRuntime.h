#ifndef CREATEEDITERRUNTIME_H
#define CREATEEDITERRUNTIME_H

#include "IEditorFactory.h" 

namespace XYBEngine
{
    SharedPtr<IEditorFactory> CreateEditorFactory(EditorApplicationBackend backend);
}
#endif // CREATEEDITERRUNTIME_H