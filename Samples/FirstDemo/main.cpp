#include "Log.h"
#include "IEditorFactory.h"
#include "EditorRuntime.h"

using namespace XYBEngine;

int main(int argc, char* argv[])
{
    InitEditorRuntime(argc, argv);

    UniquePtr<IEditorFactory> editorFactory = MakeUnique<QtEditorFactory>();
    SharedPtr<IEditorWindow> consoleWindow = editorFactory->CreateConsoleWindow();
    consoleWindow->ShowWindow();
    XYB_LOG_INFO("Hello, World!");
    return RunEditorRuntime();
}