#include "LogModule.h"

namespace XYBEngine
{
    void LogModule::Startup()
    { 
        XYB_LOG_INFO("LogModule startup");
    }

    void LogModule::Shutdown()
    { 
        XYB_LOG_INFO("LogModule shutdown");
    }

    const char* LogModule::GetName() const
    {
        return LOG_MODULE_NAME;
    }
}       