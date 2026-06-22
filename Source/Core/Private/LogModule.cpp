#include "LogModule.h"

namespace XYBEngine
{
    void LogModule::Startup()
    {
        std::cout << "LogModule startup" << std::endl;
    }

    void LogModule::Shutdown()
    {
        std::cout << "LogModule shutdown" << std::endl;
    }

    const char* LogModule::GetName() const
    {
        return LOG_MODULE_NAME;
    }
}       