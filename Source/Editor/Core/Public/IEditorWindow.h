// Copyright XYBEngine. All Rights Reserved.
//
// IEditorWindow.h - 编辑器窗口抽象接口
//
// 模块：Editor / Core
// 职责：统一编辑器各类面板/窗口的显示、隐藏与关闭操作。
//       具体 UI 实现（如 QtMainWindow、QtConsoleWindow）由 QtBackend 模块封装。

#ifndef IEDITORWINDOW_H
#define IEDITORWINDOW_H

#include "Core.h"
#include "Log.h"

namespace XYBEngine
{
    /** 编辑器窗口类型枚举，新增窗口在此扩展 */
    enum class EditorWindowType
    {   
        ConsoleWindow,  /** 控制台日志面板 */
        MainWindow,     /** 编辑器主窗口 */
        None            /** 无效/占位类型 */
    };

    /**
     * 编辑器窗口抽象接口。
     *
     * 实现类示例：QtMainWindow、QtConsoleWindow（Qt 控件 + IEditorWindow 多重继承）
     */
    class XYB_API IEditorWindow
    {
    public:
        virtual ~IEditorWindow() = default;

        /** 显示窗口（非模态） */
        virtual void Show() = 0;
        /** 隐藏窗口，不销毁实例 */
        virtual void Hide() = 0;
        /** 关闭窗口，触发底层控件销毁流程 */
        virtual void Close() = 0;
    };

    /**
     * 编辑器窗口工厂（单例）。
     *
     * 各 Qt 窗口模块通过 *Resiter() 函数注册实例；EditorLauncher 按类型获取并 Show。
     */
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

        /** 注册指定类型的窗口实例 */
        void Register(EditorWindowType type, SharedPtr<IEditorWindow> editorWindow);

        /** 移除指定类型的窗口注册 */
        void UnRegister(EditorWindowType type);

        /** 按类型获取窗口实例，未注册时返回 nullptr 并输出错误日志 */
        SharedPtr<IEditorWindow> GetEditorWindow(EditorWindowType type);
    };
}
#endif // IEDITORWINDOW_H