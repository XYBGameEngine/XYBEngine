#include "IEditorWindow.h"

namespace XYBEngine
{ 
    void EditorWindowFactory::Register(EditorWindowType type, SharedPtr<IEditorWindow> editorWindow)
    { 
        m_editorWindows[type] = editorWindow;
    }

    void EditorWindowFactory::UnRegister(EditorWindowType type)
    {
        if (m_editorWindows.find(type) == m_editorWindows.end())
        {
            XYB_LOG_ERROR("Editor Unregister window type not found");
            return;
        } 
        m_editorWindows.erase(type);
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