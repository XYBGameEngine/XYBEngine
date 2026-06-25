#ifndef EDITORRUNTIME_H
#define EDITORRUNTIME_H

#include "Core.h"

namespace XYBEngine
{
    namespace
    {
        std::unique_ptr<QApplication> g_qtApplication;
    }

    XYB_API void InitEditorRuntime(int argc, char* argv[])
    {
        if (!QApplication::instance())
        {
            g_qtApplication = std::make_unique<QApplication>(argc, argv);
        }
    }

    XYB_API int RunEditorRuntime()
    {
        if (auto* app = qobject_cast<QApplication*>(QCoreApplication::instance()))
        {
            return app->exec();
        }
        return 0;
    }
}

#endif // EDITORRUNTIME_H
