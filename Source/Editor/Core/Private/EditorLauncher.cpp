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
#include "QtApplication.h"
#include "QtConsolePanel.h"
#include "QtMainShell.h"   
#include "QtSceneViewportPanel.h"

namespace XYBEngine
{
    void EditorLauncher::Run(int argc, char* argv[])
    {  
        // 注册 Qt 后端应用实现，并初始化 QApplication
        QtApplicationResiter();
        SharedPtr<IEditorApplication> editorApplication = EditorApplicationRegister::GetInstance().GetEditorApplication();
        editorApplication->Initialize(argc, argv);
 
        // 注册并显示编辑器窗口
        QtConsolePanelResiter();   
        QtSceneViewportPanelResiter();
        auto mainShell = MakeShared<QtMainShell>();
        mainShell->Initialize();

        SharedPtr<IEditorPanel> consolePanel = EditorPanelRegister::GetInstance().CreateEditorPanel("Console");
        SharedPtr<IEditorPanel> sceneViewportPanel = EditorPanelRegister::GetInstance().CreateEditorPanel("SceneViewport");
        mainShell->AddPanel("Left", consolePanel); 
        mainShell->AddPanel("Center", sceneViewportPanel);
        mainShell->Show();

        // 进入 Qt 事件循环，返回后释放资源
        editorApplication->Run();
        editorApplication->Shutdown();
  
        EditorApplicationRegister::GetInstance().UnRegister();
    }
}
