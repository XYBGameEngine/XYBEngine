#include "IEditorPanel.h"

namespace XYBEngine
{
    void EditorPanelRegister::Register(const String& panelId, EditorPanelFactory editorPanelFactory)
    {
        m_editorPanelFactories[panelId] = editorPanelFactory;
    }
    
    SharedPtr<IEditorPanel> EditorPanelRegister::CreateEditorPanel(const String& panelId)
    {
        if (m_editorPanelFactories.find(panelId) == m_editorPanelFactories.end())
        {
            XYB_LOG_ERROR("Editor panel id not found");
            return nullptr;
        }
        return m_editorPanelFactories[panelId]();
    }
}