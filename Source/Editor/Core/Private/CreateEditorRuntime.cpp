 
#include "CreateEditorRuntime.h"

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