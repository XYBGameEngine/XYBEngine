#ifndef IEDITORFACTORY_H
#define IEDITORFACTORY_H

#include "Core.h"
#include "IEditorWindow.h" 
#include "IEditorApplication.h"

namespace XYBEngine
{
    enum class EditorWindowType
    { 
        ConsoleWindow,
        None
    };

    class XYB_API IEditorFactory
    {
    public:
        virtual ~IEditorFactory() = default;
         
        virtual SharedPtr<IEditorApplication> CreateEditorApplication() = 0;

        virtual SharedPtr<IEditorWindow> CreateEditorWindow(EditorWindowType type) = 0;
    }; 
}

#endif // IEDITORFACTORY_H