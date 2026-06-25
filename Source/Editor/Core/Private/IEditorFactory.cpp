#include "IEditorFactory.h"

namespace XYBEngine
{
    SharedPtr<IConsoleWindow> QtEditorFactory::CreateConsoleWindow()
    {
        return MakeShared<ConsoleWindow>();
    }
}