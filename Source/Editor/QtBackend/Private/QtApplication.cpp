#include "QtApplication.h"

namespace XYBEngine
{
    void QtApplication::Initialize(int argc, char** argv)
    {
        if (!QApplication::instance())
        {
            g_qtApplication = std::make_unique<QApplication>(argc, argv);
        }
    }
    void QtApplication::Tick()
    {
        if (auto* app = qobject_cast<QApplication*>(QCoreApplication::instance()))
        {
            app->exec();
        } 
    }
    void QtApplication::Shutdown()
    { 
    }
    void QtApplication::ShowWindow()
    { 
    }
}