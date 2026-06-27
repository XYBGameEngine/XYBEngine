// Copyright XYBEngine. All Rights Reserved.
//
// main.cpp - FirstDemo 编辑器入口
//
// 启动流程（与 UE 编辑器启动类似的分层）：
//   1. 从注册中心获取 UI 后端工厂（Qt）
//   2. 创建编辑器应用 + 所需窗口
//   3. Initialize → Show 窗口 → Run 主循环 → Close → Shutdown

#include "Core.h" 
#include "Log.h" 
#include "EditorLauncher.h"

using namespace XYBEngine;

int main(int argc, char* argv[])
{ 
    UniquePtr<EditorLauncher> editorLauncher = MakeUnique<EditorLauncher>();
    editorLauncher->Run(argc, argv);
    return 0;
}