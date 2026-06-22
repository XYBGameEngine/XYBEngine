#ifndef LOG_MODULE_H
#define LOG_MODULE_H

#include "IModule.h"
#include "Log.h"

namespace XYBEngine
{
    constexpr const char* LOG_MODULE_NAME = "LogModule";     
    class XYB_API LogModule : public IModule
    {
    public:
        LogModule() = default;
        ~LogModule() = default;
    public:
        const char* GetName() const override;
        void Startup() override;
        void Shutdown() override;
    };   
}

#endif