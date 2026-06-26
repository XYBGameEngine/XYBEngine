#ifndef QTFACTORY_H
#define QTFACTORY_H

#include "Core.h"
#include "IEditorFactory.h"
#include "QtApplication.h"
#include "ConsoleWindow.h"

namespace XYBEngine
{
    class QtFactory : public IEditorFactory
    {
    public:
        SharedPtr<IEditorApplication> CreateEditorApplication() override;
        SharedPtr<IEditorWindow> CreateConsoleWindow() override;
    };
}       
#endif // QTFACTORY_H