#include "CreateEditorRuntime.h"
#include "QtFactory.h"

namespace XYBEngine
{
    SharedPtr<IEditorFactory> CreateEditorFactory(EditorApplicationBackend backend)
    {
        switch (backend)
        {
        case EditorApplicationBackend::Qt:
            return MakeShared<QtFactory>();
        default:
            return nullptr;
        }
    } 
}