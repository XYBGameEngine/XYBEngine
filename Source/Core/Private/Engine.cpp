#include "Engine.h"

namespace XYBEngine
{
    void Engine::Startup()
    {
        std::cout << "Engine startup" << std::endl; 
        ModuleManager::GetInstance().RegisterModule(std::make_unique<LogModule>());
        ModuleManager::GetInstance().StartupModules();
    }

    void Engine::Shutdown()
    {
        std::cout << "Engine shutdown" << std::endl;
        ModuleManager::GetInstance().ShutdownModules();
    }
   
}       