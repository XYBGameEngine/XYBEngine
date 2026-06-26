#ifndef QTAPPLICATION_H
#define QTAPPLICATION_H

#include "Core.h"
#include <QApplication>
#include "IEditorApplication.h"

namespace XYBEngine
{
    class XYB_API QtApplication : public IEditorApplication
    {
    private: 
        UniquePtr<QApplication> g_qtApplication;
    public:
        void Initialize(int argc, char** argv) override;
        void Run() override;
        void Shutdown() override;
    };
}
#endif // QTAPPLICATION_H