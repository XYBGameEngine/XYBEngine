#include "Log.h" 
#include "CreateEditorRuntime.h"

using namespace XYBEngine;

int main(int argc, char* argv[])
{ 
    SharedPtr<IEditorFactory> editorFactory = CreateEditorFactory(EditorApplicationBackend::Qt);
    SharedPtr<IEditorApplication> editorApplication = editorFactory->CreateEditorApplication();
    SharedPtr<IEditorWindow> editorWindow = editorFactory->CreateConsoleWindow();
    editorApplication->Initialize(argc, argv);
    editorWindow->ShowWindow();
    editorApplication->Run();
    editorApplication->Shutdown();
    return 0;
}