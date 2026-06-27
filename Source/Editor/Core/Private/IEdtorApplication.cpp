#include "IEditorApplication.h"

namespace XYBEngine
{
    void EditorApplicationRegister::Register(UniquePtr<IEditorApplication> editorApplication)
    {
        m_editorApplication = editorApplication;
    }

    UniquePtr<IEditorApplication> EditorApplicationRegister::GetEditorApplication()
    {
        return m_editorApplication;
    }
}