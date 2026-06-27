#include "EditorLauncher.h"

namespace XYBEngine
{
    void EditorLauncher::Run(int argc, char* argv[])
    {
        SharedPtr<IEditorFactory> editorFactory = CreateEditorFactory::GetInstance().GetFactory(EditorApplicationBackend::Qt);
        SharedPtr<IEditorApplication> editorApplication = editorFactory->CreateEditorApplication();
        editorApplication->Initialize(argc, argv);
        
        SharedPtr<IEditorWindow> editorWindow = editorFactory->CreateEditorWindow(EditorWindowType::ConsoleWindow);

        editorWindow->Show();
        editorApplication->Run();

        editorWindow->Close();
        editorApplication->Shutdown();
    }
}