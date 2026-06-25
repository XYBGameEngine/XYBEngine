#include "Log.h"
#include "IEditorFactory.h"

using namespace XYBEngine;

int main() {     
    UniquePtr<IEditorFactory> editorFactory = MakeUnique<QtEditorFactory>();
    SharedPtr<IConsoleWindow> consoleWindow = editorFactory->CreateConsoleWindow();
    consoleWindow->ShowWindow();
    XYB_LOG_INFO("Hello, World!");
    return 0;
}