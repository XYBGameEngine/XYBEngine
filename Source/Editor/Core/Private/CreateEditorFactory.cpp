// Copyright XYBEngine. All Rights Reserved.
//
// CreateEditorFactory.cpp - 编辑器工厂注册中心实现

#include "CreateEditorFactory.h" 

namespace XYBEngine
{ 
    void CreateEditorFactory::RegisterEditorFactory(EditorApplicationBackend backend, SharedPtr<IEditorFactory> editorFactory)
    {
        m_editorFactories[backend] = editorFactory;
    }

    SharedPtr<IEditorFactory> CreateEditorFactory::GetFactory(EditorApplicationBackend backend)
    {
        auto it = m_editorFactories.find(backend);
        if (it != m_editorFactories.end())
        {
            return it->second;
        }
        // 未注册的后端：通常意味着对应模块未链接或未执行静态注册
        XYBEngine::Log::GetInstance().LogError("Editor factory not found for backend");
        return nullptr; 
    }
}