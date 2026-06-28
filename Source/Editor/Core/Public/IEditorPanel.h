#ifndef IEDITORPANEL_H
#define IEDITORPANEL_H

#include "Core.h"
#include "Log.h"

namespace XYBEngine
{   
    class XYB_API IEditorPanel
    {
    public:
        virtual ~IEditorPanel() = default;

        virtual const char* GetPanelId() const = 0;
        virtual void Show() = 0;
        virtual void Hide() = 0;
        virtual void Close() = 0;
    };

    using EditorPanelFactory = SharedPtr<IEditorPanel>(*)();

    class XYB_API EditorPanelRegister
    {
    private:
        UnOrderedMap<String, EditorPanelFactory> m_editorPanelFactories;
    public:
        static EditorPanelRegister& GetInstance()
        {
            static EditorPanelRegister s_instance;
            return s_instance;
        }

        void Register(const String& panelId, EditorPanelFactory editorPanelFactory);
        SharedPtr<IEditorPanel> CreateEditorPanel(const String& panelId);
    };
}

#endif
