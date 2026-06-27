#include "Log.h" 
#include "CreateEditorFactory.h"

using namespace XYBEngine;

int main(int argc, char* argv[])
{ 
    SharedPtr<IEditorFactory> editorFactory = CreateEditorFactory::GetInstance().GetFactory(EditorApplicationBackend::Qt);
    SharedPtr<IEditorApplication> editorApplication = editorFactory->CreateEditorApplication();
    SharedPtr<IEditorWindow> consoleWindow = editorFactory->CreateEditorWindow(EditorWindowType::ConsoleWindow); 
    
    editorApplication->Initialize(argc, argv);
    
    consoleWindow->Show();
    editorApplication->Run(); 

    consoleWindow->Close();
    editorApplication->Shutdown();

    return 0;
}