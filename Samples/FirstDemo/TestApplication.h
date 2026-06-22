#include "IApplication.h"
#include "Engine.h"
#include "LogModule.h"
#include "ModuleManager.h"

namespace XYBEngine
{
    class TestApplication : public IApplication
    {
    public:
        TestApplication() : IApplication(UniquePtr<Engine>(new Engine())) {}
        ~TestApplication() = default;
    };
}