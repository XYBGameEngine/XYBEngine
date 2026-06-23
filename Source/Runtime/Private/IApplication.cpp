#include "IApplication.h"

namespace XYBEngine
{
    int IApplication::Run(int argc, char** argv)
    {
        m_engine = std::make_unique<Engine>();
        RegisterModules(m_engine->GetModuleManager());

        OnInit();
        m_engine->Init();

        m_isRunning = true;

        while (m_isRunning)
        {
            OnUpdate();
        } 

        OnShutdown();
        m_engine->Shutdown();

        m_isRunning = false;

        return 0;
    }
}