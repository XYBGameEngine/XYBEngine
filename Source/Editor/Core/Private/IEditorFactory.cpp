#include "IEditorFactory.h"
#include "ConsoleWindow.h"

namespace XYBEngine
{
    SharedPtr<IEditorWindow> QtEditorFactory::CreateConsoleWindow()
    {
        return MakeShared<ConsoleWindow>();
    }
}