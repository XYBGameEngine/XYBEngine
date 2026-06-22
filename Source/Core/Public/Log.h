#ifndef LOG_H
#define LOG_H

#include "Core.h"
#include <spdlog/spdlog.h>

namespace XYBEngine
{
    class XYB_API Log
    {
    public:
        Log() = default;
        ~Log() = default;

        static Log& GetInstance(){
            static Log s_instance;
            return s_instance;
        }
    public:

        void SetLogLevel(spdlog::level::level_enum level);
        void LogInfo(const std::string& message);
        void LogWarning(const std::string& message);
        void LogError(const std::string& message);
        void LogFatal(const std::string& message);
        void LogDebug(const std::string& message);
        void LogTrace(const std::string& message);
        void LogCritical(const std::string& message);
    };

    #define XYB_LOG_INFO(message) Log::GetInstance().LogInfo(message)
    #define XYB_LOG_WARNING(message) Log::GetInstance().LogWarning(message)
    #define XYB_LOG_ERROR(message) Log::GetInstance().LogError(message)
    #define XYB_LOG_FATAL(message) Log::GetInstance().LogFatal(message)
    #define XYB_LOG_DEBUG(message) Log::GetInstance().LogDebug(message)
    #define XYB_LOG_TRACE(message) Log::GetInstance().LogTrace(message)
    #define XYB_LOG_CRITICAL(message) Log::GetInstance().LogCritical(message)    
}

#endif