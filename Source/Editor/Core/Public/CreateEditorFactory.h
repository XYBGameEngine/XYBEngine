// Copyright XYBEngine. All Rights Reserved.
//
// CreateEditorFactory.h - 编辑器工厂注册中心
//
// 模块：Editor / Core
// 职责：管理各 UI 后端的 IEditorFactory 注册与查找（类似 UE 的模块/插件注册表）。
// 流程：后端模块在静态初始化阶段 RegisterEditorFactory → 入口代码 GetFactory 获取

#ifndef CREATEEDITERFACTORY_H
#define CREATEEDITERFACTORY_H

#include "IEditorFactory.h" 
#include "Core.h"
#include "Log.h"

namespace XYBEngine
{   
    /** 编辑器 UI 后端类型，与 IEditorFactory 实现一一对应 */
    enum class EditorApplicationBackend
    {
        Qt,
        None
    };
  
    /**
     * 编辑器工厂注册中心（单例）。
     *
     * 用法：
     *   1. 后端模块加载时：RegisterEditorFactory(Backend::Qt, factory)
     *   2. 程序入口：GetFactory(Backend::Qt)->CreateEditorApplication()
     */
    class XYB_API CreateEditorFactory
    {
    private:
        UnOrderedMap<EditorApplicationBackend, SharedPtr<IEditorFactory>> m_editorFactories;
    public:
        static CreateEditorFactory& GetInstance()
        {
            static CreateEditorFactory s_instance;
            return s_instance;
        }

        void RegisterEditorFactory(EditorApplicationBackend backend, SharedPtr<IEditorFactory> editorFactory);
        
        SharedPtr<IEditorFactory> GetFactory(EditorApplicationBackend backend);
    };
 
}
#endif // CREATEEDITERFACTORY_H