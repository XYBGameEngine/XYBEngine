#include "QtFactory.h" 

namespace XYBEngine
{
    SharedPtr<IEditorApplication> QtFactory::CreateEditorApplication()
    {
        return MakeShared<QtApplication>();
    }
    SharedPtr<IEditorWindow> QtFactory::CreateConsoleWindow()
    {
        return MakeShared<ConsoleWindow>();
    }
}