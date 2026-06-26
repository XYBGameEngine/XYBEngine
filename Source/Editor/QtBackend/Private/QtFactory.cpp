#include "QtFactory.h" 

namespace XYBEngine
{
    SharedPtr<IEditorApplication> QtFactory::CreateEditorApplication()
    {
        return MakeShared<QtApplication>();
    }
    SharedPtr<IEditorWindow> QtFactory::CreateEditorWindow(EditorWindowType type)
    {
        switch (type)
        {
        case EditorWindowType::ConsoleWindow:
            return MakeShared<ConsoleWindow>();
        default:
            return nullptr;
        }
    }
}