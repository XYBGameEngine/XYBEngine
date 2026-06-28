#include "EditorLauncher.h"

#include "Core.h" 
#include "IEditorApplication.h"
#include "IEditorWindow.h"  
#include "QtApplication.h"
#include "QtConsoleWindow.h"
#include "QtMainWindow.h"

namespace XYBEngine
{
    void EditorLauncher::Run(int argc, char* argv[])
    {  
        QtApplicationResiter();
        SharedPtr<IEditorApplication> editorApplication = EditorApplicationRegister::GetInstance().GetEditorApplication();
        editorApplication->Initialize(argc, argv);
 
        QtConsoleWindowResiter();
        QtMainWindowResiter();
        SharedPtr<IEditorWindow> mainWindow = EditorWindowFactory::GetInstance().GetEditorWindow(EditorWindowType::MainWindow);
        SharedPtr<IEditorWindow> consoleWindow = EditorWindowFactory::GetInstance().GetEditorWindow(EditorWindowType::ConsoleWindow);
        
        mainWindow->Show();
        consoleWindow->Show();  

        editorApplication->Run();
        editorApplication->Shutdown();

        EditorWindowFactory::GetInstance().UnRegister(EditorWindowType::ConsoleWindow); 
        EditorWindowFactory::GetInstance().UnRegister(EditorWindowType::MainWindow);
        EditorApplicationRegister::GetInstance().UnRegister();
    }
}