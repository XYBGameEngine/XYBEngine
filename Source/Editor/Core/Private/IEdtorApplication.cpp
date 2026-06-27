#include "IEditorApplication.h"

namespace XYBEngine
{
    void EditorApplicationRegister::Register(SharedPtr<IEditorApplication> editorApplication)
    {
        m_editorApplication = editorApplication;
    }

    SharedPtr<IEditorApplication> EditorApplicationRegister::GetEditorApplication()
    {
        return m_editorApplication;
    }
}