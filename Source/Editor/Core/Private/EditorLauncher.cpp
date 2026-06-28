// Copyright XYBEngine. All Rights Reserved.
//
// EditorLauncher.cpp - 编辑器启动流程实现
//
// 启动顺序：
//   1. 注册 Qt 应用与各类窗口到全局工厂
//   2. Initialize → Show 主窗口与控制台 → Run 主循环
//   3. Shutdown → 反注册窗口与应用

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
        // 注册 Qt 后端应用实现，并初始化 QApplication
        QtApplicationResiter();
        SharedPtr<IEditorApplication> editorApplication = EditorApplicationRegister::GetInstance().GetEditorApplication();
        editorApplication->Initialize(argc, argv);
 
        // 注册并显示编辑器窗口
        QtConsoleWindowResiter();
        QtMainWindowResiter();
        SharedPtr<IEditorWindow> mainWindow = EditorWindowFactory::GetInstance().GetEditorWindow(EditorWindowType::MainWindow);
        SharedPtr<IEditorWindow> consoleWindow = EditorWindowFactory::GetInstance().GetEditorWindow(EditorWindowType::ConsoleWindow);
        
        mainWindow->Show();
        consoleWindow->Show();  

        // 进入 Qt 事件循环，返回后释放资源
        editorApplication->Run();
        editorApplication->Shutdown();

        EditorWindowFactory::GetInstance().UnRegister(EditorWindowType::ConsoleWindow); 
        EditorWindowFactory::GetInstance().UnRegister(EditorWindowType::MainWindow);
        EditorApplicationRegister::GetInstance().UnRegister();
    }
}
