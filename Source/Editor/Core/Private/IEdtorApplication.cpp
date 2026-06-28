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