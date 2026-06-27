// Copyright XYBEngine. All Rights Reserved.
//
// IEditorFactory.h - 编辑器工厂接口
//
// 模块：Editor / Core
// 职责：按类型创建编辑器应用实例与各类编辑器窗口。
//       每个 UI 后端（Qt、未来可能的 Win32 等）提供各自的 IEditorFactory 实现。

#ifndef IEDITORFACTORY_H
#define IEDITORFACTORY_H

#include "Core.h"
#include "IEditorWindow.h" 
#include "IEditorApplication.h"

namespace XYBEngine
{
    /** 编辑器窗口类型枚举，新增窗口在此扩展 */
    enum class EditorWindowType
    { 
        ConsoleWindow,
        None
    };

    /**
     * 编辑器工厂抽象接口。
     *
     * 由 CreateEditorFactory 按 EditorApplicationBackend 注册与查找。
     */
    class XYB_API IEditorFactory
    {
    public:
        virtual ~IEditorFactory() = default;

        /** 创建与当前后端绑定的编辑器应用实例 */
        virtual SharedPtr<IEditorApplication> CreateEditorApplication() = 0;

        /** 按类型创建编辑器窗口，未知类型应返回 nullptr 并记录错误 */
        virtual SharedPtr<IEditorWindow> CreateEditorWindow(EditorWindowType type) = 0;
    }; 
}

#endif // IEDITORFACTORY_H