// Copyright XYBEngine. All Rights Reserved.
//
// main.cpp - FirstDemo 编辑器入口
//
// 启动流程（与 UE 编辑器启动类似的分层）：
//   1. 从注册中心获取 UI 后端工厂（Qt）
//   2. 创建编辑器应用 + 所需窗口
//   3. Initialize → Show 窗口 → Run 主循环 → Close → Shutdown

#include "Log.h" 
#include "CreateEditorFactory.h"

using namespace XYBEngine;

int main(int argc, char* argv[])
{ 
    // -----------------------------------------------------------------------
    // Phase 1: 解析后端，创建核心对象
    // QtFactory 已在链接 XYBEditor 库时通过静态注册完成注册
    // -----------------------------------------------------------------------
    SharedPtr<IEditorFactory> editorFactory = CreateEditorFactory::GetInstance().GetFactory(EditorApplicationBackend::Qt);
    SharedPtr<IEditorApplication> editorApplication = editorFactory->CreateEditorApplication();
    SharedPtr<IEditorWindow> consoleWindow = editorFactory->CreateEditorWindow(EditorWindowType::ConsoleWindow); 
    
    // -----------------------------------------------------------------------
    // Phase 2: 初始化并进入主循环
    // -----------------------------------------------------------------------
    editorApplication->Initialize(argc, argv);
    
    consoleWindow->Show();
    editorApplication->Run(); // 阻塞，直到 Qt 事件循环结束

    // -----------------------------------------------------------------------
    // Phase 3: 清理
    // -----------------------------------------------------------------------
    consoleWindow->Close();
    editorApplication->Shutdown();

    return 0;
}