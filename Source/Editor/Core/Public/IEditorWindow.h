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
#include "Log.h"

namespace XYBEngine
{
    /** 编辑器窗口类型枚举，新增窗口在此扩展 */
    enum class EditorWindowType
    { 
        ConsoleWindow,
        None
    };

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

    class XYB_API EditorWindowFactory
    {
    private:
        UnOrderedMap<EditorWindowType, SharedPtr<IEditorWindow>> m_editorWindows;
    public: 
        static EditorWindowFactory& GetInstance()
        {
            static EditorWindowFactory s_instance;
            return s_instance;
        }

        void Register(EditorWindowType type, SharedPtr<IEditorWindow> editorWindow);

        void UnRegister(EditorWindowType type);

        SharedPtr<IEditorWindow> GetEditorWindow(EditorWindowType type);
    };
}
#endif // IEDITORWINDOW_H