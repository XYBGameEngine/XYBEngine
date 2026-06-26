#ifndef IEDITORFACTORY_H
#define IEDITORFACTORY_H

#include "Core.h"
#include "IEditorWindow.h"

namespace XYBEngine
{
    class XYB_API IEditorFactory
    {
    public:
        virtual ~IEditorFactory() = default;
        
        virtual SharedPtr<IEditorWindow> CreateConsoleWindow() = 0;
    };


    class XYB_API QtEditorFactory : public IEditorFactory
    {
    public:
        SharedPtr<IEditorWindow> CreateConsoleWindow() override;
    };

}
#endif // IEDITORFACTORY_H