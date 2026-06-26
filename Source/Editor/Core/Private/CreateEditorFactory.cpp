#include "CreateEditorFactory.h"
#include "QtFactory.h"

namespace XYBEngine
{
    XYB_API SharedPtr<IEditorFactory> CreateEditorFactory(EditorApplicationBackend backend)
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