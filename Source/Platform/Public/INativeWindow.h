#ifndef INATIVEWINDOW_H
#define INATIVEWINDOW_H
 
#include "Core.h"

namespace XYBEngine
{
    enum class NativeWindowType
    {
        Windows,
        Linux,
        MacOS,
        Android,
        iOS, 
        OtherPlatform
    };

    struct NativeWindowHandle
    {
        NativeWindowType type;
        void* handle;
        void* display;
        void* layer;
    };

    class XYB_API INativeWindow
    {
    public:
        virtual ~INativeWindow() = default;

        virtual uint32 GetWidth() = 0;
        virtual uint32 GetHeight() = 0;

        virtual void Create(NativeWindowHandle nativeWindowHandle) = 0;
        virtual void Resize(uint32 width, uint32 height) = 0;
        virtual NativeWindowHandle GetNativeWindow() = 0; 
    };
}

#endif