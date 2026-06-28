// Copyright XYBEngine. All Rights Reserved.
//
// EditorLauncher.h - 编辑器启动入口
//
// 模块：Editor / Core
// 职责：编排编辑器完整启动流程（注册 UI 后端 → 初始化 → 显示窗口 → 主循环 → 清理）。
//       宿主程序（如 FirstDemo）只需构造并调用 Run，无需感知 Qt 细节。

#ifndef EDITORLAUNCHER_H
#define EDITORLAUNCHER_H

namespace XYBEngine
{
    /**
     * 编辑器启动器。
     *
     * 内部依次完成：Qt 应用注册、窗口注册、Initialize、Show、Run、Shutdown、反注册。
     */
    class EditorLauncher
    {
    public:
        EditorLauncher() = default;

        /** 执行完整编辑器启动与关闭流程，阻塞直到主事件循环退出 */
        void Run(int argc, char* argv[]);
    };
}

#endif // EDITORLAUNCHER_H
