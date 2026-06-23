#include "Engine.h"

namespace XYBEngine
{
    Engine::~Engine()
    {
        if (m_isInit)
        {
            Shutdown();
        }
    }    

    void Engine::RegisterEngineModules()
    {
        m_moduleManager.RegisterModule(std::make_unique<LogModule>());
    }   

    void Engine::Init()
    { 
        RegisterEngineModules();
        m_moduleManager.StartupModules();

        XYB_LOG_WARNING("Engine Init"); 

        m_isInit = true;
    }

    void Engine::Shutdown()
    {
        if (!m_isInit)
        {
            return;
        } 

        m_moduleManager.ShutdownModules();
        m_moduleManager.ClearModules();

        XYB_LOG_WARNING("Engine Shutdown");

        m_isInit = false;
    } 
}