#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core.h"
#include "Engine.h"

namespace XYBEngine
{
    class XYB_API IApplication
    {
    private:
        UniquePtr<Engine> m_engine;
    public:
        IApplication(UniquePtr<Engine> engine) : m_engine(std::move(engine)) { 
        }
        ~IApplication(){  
            m_engine.reset(); 
        }
    public:  
        void Startup() {m_engine->Startup();}
        void Shutdown() {m_engine->Shutdown();}
    };
}

#endif