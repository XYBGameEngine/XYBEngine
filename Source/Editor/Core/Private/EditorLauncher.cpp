#include "EditorLauncher.h"

#include "Core.h" 
#include "IEditorApplication.h"
#include "IEditorWindow.h"

namespace XYBEngine
{
    void EditorLauncher::Run(int argc, char* argv[])
    {
        SharedPtr<IEditorApplication> editorApplication = EditorApplicationRegister::GetInstance().GetEditorApplication();
        editorApplication->Initialize(argc, argv);

        SharedPtr<IEditorWindow> editorWindow = EditorWindowFactory::GetInstance().GetEditorWindow(EditorWindowType::ConsoleWindow);
        
        editorWindow->Show();
        editorApplication->Run();

        editorWindow->Close();
        editorApplication->Shutdown();
    }
}