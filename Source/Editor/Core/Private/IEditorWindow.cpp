#include "IEditorWindow.h"

namespace XYBEngine
{ 
    void EditorWindowFactory::Register(EditorWindowType type, SharedPtr<IEditorWindow> editorWindow)
    { 
        m_editorWindows[type] = editorWindow;
    }

    SharedPtr<IEditorWindow> EditorWindowFactory::GetEditorWindow(EditorWindowType type)
    {
        if (m_editorWindows.find(type) == m_editorWindows.end())
        {
            XYB_LOG_ERROR("Editor window type not found");
            return nullptr;
        }
        return m_editorWindows[type];
    }
}