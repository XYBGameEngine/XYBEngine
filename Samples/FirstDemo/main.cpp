#include "Log.h" 
#include "CreateEditorFactory.h"

using namespace XYBEngine;

int main(int argc, char* argv[])
{ 
    SharedPtr<IEditorFactory> editorFactory = CreateEditorFactory::GetInstance().GetFactory(EditorApplicationBackend::Qt);
    SharedPtr<IEditorWindow> editorApplication = editorFactory->createEditorWindow(EditorWindowType::ApplicationWindow);
    SharedPtr<IEditorWindow> editorWindow = editorFactory->CreateEditorWindow(EditorWindowType::ConsoleWindow);
    editorApplication->Initialize(argc, argv);
    editorWindow->ShowWindow();
    editorApplication->Run();
    editorApplication->Shutdown();
    return 0;
}