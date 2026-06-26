#ifndef QTAPPLICATION_H
#define QTAPPLICATION_H

#include "Core.h"
#include <QApplication>
#include "IEditorWindow.h"

namespace XYBEngine
{
    class XYB_API QtApplication : public IEditorWindow
    {
    private: 
        UniquePtr<QApplication> g_qtApplication;
    public:
        void Initialize(int argc, char** argv) override;
        void Tick() override;
        void Shutdown() override;
        void ShowWindow() override;
    };
}
#endif // QTAPPLICATION_H