#ifndef IEDITORFACTORY_H
#define IEDITORFACTORY_H

#include "Core.h"
#include "IConsoleWindow.h"

namespace XYBEngine
{
    class XYB_API IEditorFactory
    {
    public:
        virtual ~IEditorFactory() = default;
        
        virtual SharedPtr<IConsoleWindow> CreateConsoleWindow() = 0;
    };


    class XYB_API QtEditorFactory : public IEditorFactory
    {
    public:
        SharedPtr<IConsoleWindow> CreateConsoleWindow() override;
    };

}
#endif // IEDITORFACTORY_H