#ifndef ICONSOLEWINDOW_H
#define ICONSOLEWINDOW_H

#include "Core.h"

namespace XYBEngine
{
    class XYB_API IConsoleWindow
    {
    public:
        virtual ~IConsoleWindow() = default;

        virtual void ShowWindow() = 0; 
    };
}
#endif // ICONSOLEWINDOW_H