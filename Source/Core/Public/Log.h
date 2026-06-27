// Copyright XYBEngine. All Rights Reserved.
//
// Log.h - 全局日志门面
//
// 模块：Core
// 职责：封装 spdlog，提供引擎统一的日志入口与便捷宏（XYB_LOG_*）。
// 用法：Log::GetInstance().LogInfo("...") 或 XYB_LOG_INFO("...")

#ifndef LOG_H
#define LOG_H

#include "Core.h"
#include <spdlog/spdlog.h>

namespace XYBEngine
{
    /**
     * 全局日志单例。底层委托 spdlog，级别可通过 SetLogLevel 调整。
     */
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

    // 便捷宏：在任意模块中快速输出日志，无需手动获取单例
    #define XYB_LOG_INFO(message) Log::GetInstance().LogInfo(message)
    #define XYB_LOG_WARNING(message) Log::GetInstance().LogWarning(message)
    #define XYB_LOG_ERROR(message) Log::GetInstance().LogError(message)
    #define XYB_LOG_FATAL(message) Log::GetInstance().LogFatal(message)
    #define XYB_LOG_DEBUG(message) Log::GetInstance().LogDebug(message)
    #define XYB_LOG_TRACE(message) Log::GetInstance().LogTrace(message)
    #define XYB_LOG_CRITICAL(message) Log::GetInstance().LogCritical(message)    
}

#endif