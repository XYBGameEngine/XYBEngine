#include "QtFactory.h" 

namespace XYBEngine
{
    struct QtFactoryRegistration
    {
        QtFactoryRegistration()
        {
            CreateEditorFactory::GetInstance().RegisterEditorFactory(EditorApplicationBackend::Qt, MakeShared<QtFactory>());
            Log::GetInstance().LogInfo("QtFactory registered");
        }
    };
    static QtFactoryRegistration s_qtFactoryRegistration;
 
    SharedPtr<IEditorWindow> QtFactory::CreateEditorWindow(EditorWindowType type)
    {
        switch (type)
        {
        case EditorWindowType::ApplicationWindow:
            return MakeShared<QtApplication>();
        case EditorWindowType::ConsoleWindow:
            return MakeShared<ConsoleWindow>();
        default:
            XYB_LOG_ERROR("Invalid editor window type");
            return nullptr;
        }
    }
}