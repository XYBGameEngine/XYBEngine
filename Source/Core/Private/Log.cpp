#include "Log.h"

namespace XYBEngine
{

    void Log::SetLogLevel(spdlog::level::level_enum level)
    {
        spdlog::set_level(level);
    }
    void Log::LogInfo(const std::string& message)
    {
        spdlog::info(message);
    }
    void Log::LogWarning(const std::string& message)
    {
        spdlog::warn(message);
    }
    void Log::LogError(const std::string& message)
    {
        spdlog::error(message);
    }
    void Log::LogFatal(const std::string& message)
    {
        spdlog::critical(message);
    }
    void Log::LogDebug(const std::string& message)
    {
        spdlog::debug(message);
    }
    void Log::LogTrace(const std::string& message)
    {
        spdlog::trace(message);
    }
    void Log::LogCritical(const std::string& message)
    {
        spdlog::critical(message);
    }
}   