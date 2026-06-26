#ifndef CREATEEDITERFACTORY_H
#define CREATEEDITERFACTORY_H

#include "IEditorFactory.h" 
#include "Core.h"
#include "Log.h"

namespace XYBEngine
{   
    enum class EditorApplicationBackend
    {
        Qt,
        None
    };
  
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