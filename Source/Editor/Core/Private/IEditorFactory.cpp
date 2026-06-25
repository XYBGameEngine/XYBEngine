#include "IEditorFactory.h"
#include "ConsoleWindow.h"

namespace XYBEngine
{
    SharedPtr<IConsoleWindow> QtEditorFactory::CreateConsoleWindow()
    {
        return MakeShared<ConsoleWindow>();
    }
}