#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core.h"
#include "Engine.h"

namespace XYBEngine
{
    struct ApplicationSettings
    {
        int windowWidth = 1280;
        int windowHeight = 720;
        const char* startupScene = nullptr;
        bool enableVsync = true;
    };

    class XYB_API IApplication
    {
    private:
        UniquePtr<Engine> m_engine;
        bool m_isRunning = false;
    public:
        IApplication() = default;
        ~IApplication() = default;
    public:  
        virtual void RegisterModules(ModuleManager& moduleManager){}
        
        virtual void OnInit(){}

        virtual void OnShutdown(){}

        virtual void OnUpdate(){}

        // 唯一对外入口
        int Run(int argc = 0, char** argv = nullptr);
    };
}

#endif