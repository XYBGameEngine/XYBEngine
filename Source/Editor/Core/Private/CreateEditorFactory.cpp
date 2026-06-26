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
        XYBEngine::Log::GetInstance().LogError("Editor factory not found for backend");
        return nullptr; 
    }
}