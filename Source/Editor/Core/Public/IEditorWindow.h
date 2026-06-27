// Copyright XYBEngine. All Rights Reserved.
//
// IEditorWindow.h - 编辑器窗口抽象接口
//
// 模块：Editor / Core
// 职责：统一编辑器各类面板/窗口的显示、隐藏与关闭操作。
//       具体 UI 实现（如 QtConsoleWindow）由后端模块封装，对外只暴露此接口。

#ifndef IEDITORWINDOW_H
#define IEDITORWINDOW_H

#include "Core.h"

namespace XYBEngine
{
    /**
     * 编辑器窗口抽象接口。
     *
     * 实现类示例：ConsoleWindow（内部持有 Qt 控件）
     */
    class XYB_API IEditorWindow
    {
    public:
        virtual ~IEditorWindow() = default;

        virtual void Show() = 0;
        virtual void Hide() = 0;
        virtual void Close() = 0;
    };
}
#endif // IEDITORWINDOW_H