#ifndef MODULE_H
#define MODULE_H

#include "Core.h"

namespace XYBEngine
{
    class XYB_API IModule
    {
    public:
        IModule() = default;
        ~IModule() = default;
    public:
        virtual const char* GetName() const = 0; 
        virtual void Startup() = 0;
        virtual void Shutdown() = 0;
    };
}

#endif