// Copyright XYBEngine. All Rights Reserved.
//
// main.cpp - FirstDemo 编辑器入口
//
// 启动流程：构造 EditorLauncher 并调用 Run，内部完成注册、初始化、
//           显示窗口、主循环与资源清理（详见 EditorLauncher.cpp）。

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