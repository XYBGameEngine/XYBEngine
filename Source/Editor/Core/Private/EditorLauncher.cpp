#include "EditorLauncher.h"

#include "Core.h" 
#include "IEditorApplication.h"
#include "IEditorWindow.h"  
#include "QtApplication.h"
#include "QtConsoleWindow.h"

namespace XYBEngine
{
    void EditorLauncher::Run(int argc, char* argv[])
    {  
        QtApplicationResiter();
        SharedPtr<IEditorApplication> editorApplication = EditorApplicationRegister::GetInstance().GetEditorApplication();
        editorApplication->Initialize(argc, argv);
 
        QtConsoleWindowResiter();
        SharedPtr<IEditorWindow> editorWindow = EditorWindowFactory::GetInstance().GetEditorWindow(EditorWindowType::ConsoleWindow);
        
        editorWindow->Show();
        editorApplication->Run();

        editorWindow->Close();
        editorApplication->Shutdown();
        
        EditorWindowFactory::GetInstance().UnRegister(EditorWindowType::ConsoleWindow);
        EditorApplicationRegister::GetInstance().UnRegister();
    }
}