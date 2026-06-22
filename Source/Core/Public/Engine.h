#ifndef ENGINE_H
#define ENGINE_H
 
#include "ModuleManager.h"
#include "LogModule.h"

namespace XYBEngine
{
    class XYB_API Engine
    { 
    public:
        Engine() = default;
        ~Engine() = default;  
        void Startup();
        void Shutdown();  
    };      
}

#endif