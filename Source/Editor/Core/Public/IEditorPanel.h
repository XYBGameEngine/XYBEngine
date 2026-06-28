#ifndef IEDITORPANEL_H
#define IEDITORPANEL_H

#include "Core.h"
#include "Log.h"

namespace XYBEngine
{  
    // QtConsolePanel.h —— 常量属于 Console 模块，不属于 Core
    namespace EditorPanelIds
    {
        inline constexpr const char* Console  = "Console";
        inline constexpr const char* Viewport = "Viewport";
    }

    class IEditorPanel
    {
    public:
        virtual ~IEditorPanel() = default;

        virtual const char* GetPanelId() const = 0;
        virtual void Show() = 0;
        virtual void Hide() = 0;
        virtual void Close() = 0;
    };

    using EditorPanelFactory = SharedPtr<IEditorPanel>(*)();

    class EditorPanelRegister
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