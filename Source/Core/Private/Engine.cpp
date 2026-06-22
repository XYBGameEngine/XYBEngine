#include "Engine.h"

namespace XYBEngine
{
    void Engine::Startup()
    {
        XYB_LOG_WARNING("Engine startup"); 
        ModuleManager::GetInstance().RegisterModule(std::make_unique<LogModule>());
        ModuleManager::GetInstance().StartupModules();
    }

    void Engine::Shutdown()
    {
        XYB_LOG_WARNING("Engine shutdown");
        ModuleManager::GetInstance().ShutdownModules();
    }
   
}       