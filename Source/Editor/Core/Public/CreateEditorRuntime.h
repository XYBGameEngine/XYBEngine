#ifndef CREATEEDITERRUNTIME_H
#define CREATEEDITERRUNTIME_H

#include "QtFactory.h"
#include "IEditorFactory.h" 

namespace XYBEngine
{
    SharedPtr<IEditorFactory> CreateEditorFactory(EditorApplicationBackend backend);
}
#endif // CREATEEDITERRUNTIME_H