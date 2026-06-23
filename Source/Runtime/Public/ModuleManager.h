#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H

#include "IModule.h"

namespace XYBEngine
{
    class XYB_API ModuleManager
    {
    private: 
        UniqueVectorPtr<IModule> m_modules;
    public:
        ModuleManager() = default;
        ~ModuleManager() = default; 
 
    public:
        void RegisterModule(UniquePtr<IModule> module);
        void UnregisterModule(UniquePtr<IModule> module);
        void StartupModules();
        void ShutdownModules();
        void ClearModules();
    };    
}

#endif