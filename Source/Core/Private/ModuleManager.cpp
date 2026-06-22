#include "ModuleManager.h"

namespace XYBEngine
{  
    void ModuleManager::RegisterModule(UniquePtr<IModule> module)
    {
        m_modules.push_back(std::move(module));
    }

    void ModuleManager::UnregisterModule(UniquePtr<IModule> module)
    {
        m_modules.erase(std::remove(m_modules.begin(), m_modules.end(), module), m_modules.end());
    }
    
    void ModuleManager::StartupModules()
    {
        for (auto& module : m_modules)
        {
            module->Startup();
        }
    }
    
    void ModuleManager::ShutdownModules()
    {
        for (auto it = m_modules.rbegin(); it != m_modules.rend(); ++it)
        {
            (*it)->Shutdown();
        }
    }
}