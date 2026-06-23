#ifndef ENGINE_H
#define ENGINE_H
 
#include "ModuleManager.h"
#include "LogModule.h"

namespace XYBEngine
{
    class XYB_API Engine
    { 
    private:
        bool m_isInit = false;
        ModuleManager m_moduleManager;
        
        void RegisterEngineModules();

    public:
        Engine() = default;
        ~Engine();

        void Init();

        void Shutdown();  

        ModuleManager& GetModuleManager(){ return m_moduleManager; }
    };      
}

#endif