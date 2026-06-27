#ifndef IEDITORAPPLICATION_H
#define IEDITORAPPLICATION_H

#include "Core.h"

namespace XYBEngine
{
    class XYB_API IEditorApplication
    {
    public:
        virtual ~IEditorApplication() = default;

        virtual void Initialize(int argc, char** argv) = 0;
        virtual void Run() = 0;
        virtual void Shutdown() = 0;
    };
}
#endif // IEDITORAPPLICATION_H