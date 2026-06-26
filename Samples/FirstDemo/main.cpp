#include "Log.h" 
#include "CreateEditorFactory.h"

using namespace XYBEngine;

int main(int argc, char* argv[])
{ 
    SharedPtr<IEditorFactory> editorFactory = CreateEditorFactory(EditorApplicationBackend::Qt);
    SharedPtr<IEditorApplication> editorApplication = editorFactory->CreateEditorApplication();
    SharedPtr<IEditorWindow> editorWindow = editorFactory->CreateEditorWindow(EditorWindowType::ConsoleWindow);
    editorApplication->Initialize(argc, argv);
    editorWindow->ShowWindow();
    editorApplication->Run();
    editorApplication->Shutdown();
    return 0;
}