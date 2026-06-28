// Copyright XYBEngine. All Rights Reserved.
//
// IEdtorApplication.cpp - EditorApplicationRegister 单例实现
//
// 模块：Editor / Core
// 职责：维护当前注册的 IEditorApplication 实例，供 EditorLauncher 获取与释放。

#include "IEditorApplication.h"

namespace XYBEngine
{
    void EditorApplicationRegister::Register(SharedPtr<IEditorApplication> editorApplication)
    {
        m_editorApplication = editorApplication;
    }

    void EditorApplicationRegister::UnRegister()
    {
        m_editorApplication = nullptr;
    }

    SharedPtr<IEditorApplication> EditorApplicationRegister::GetEditorApplication()
    {
        return m_editorApplication;
    }
}
