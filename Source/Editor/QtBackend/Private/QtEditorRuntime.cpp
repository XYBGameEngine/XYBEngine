#include "EditorRuntime.h"

#include <QApplication>
#include <QCoreApplication>
#include <memory>

namespace XYBEngine
{
    namespace
    {
        std::unique_ptr<QApplication> g_qtApplication;
    }

    void InitEditorRuntime(int argc, char* argv[])
    {
        if (!QApplication::instance())
        {
            g_qtApplication = std::make_unique<QApplication>(argc, argv);
        }
    }

    int RunEditorRuntime()
    {
        if (auto* app = qobject_cast<QApplication*>(QCoreApplication::instance()))
        {
            return app->exec();
        }
        return 0;
    }
}
