#ifndef QTFACTORY_H
#define QTFACTORY_H

#include "Core.h"
#include "IEditorFactory.h"
#include "QtApplication.h"
#include "ConsoleWindow.h"
#include "CreateEditorFactory.h"
#include "Log.h"

namespace XYBEngine
{
    class QtFactory : public IEditorFactory
    {
    public: 
        SharedPtr<IEditorWindow> CreateEditorWindow(EditorWindowType type) override;
    };
}       
#endif // QTFACTORY_H