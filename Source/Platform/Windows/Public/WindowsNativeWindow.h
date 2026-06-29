#ifndef WINDOWSNATIVEWINDOW_H
#define WINDOWSNATIVEWINDOW_H

#include "INativeWindow.h"
#include <windows.h>

namespace XYBEngine
{
    class WindowsNativeWindow : public INativeWindow
    {
        private:
            uint32 m_width = 0;
            uint32 m_height = 0;
            HWND m_hwnd = nullptr; 
            NativeWindowHandle m_nativeWindowHandle;
        public:
            WindowsNativeWindow() = default;
            ~WindowsNativeWindow() override;

            uint32 GetWidth() override;
            uint32 GetHeight() override;
            
            void Create(NativeWindowHandle nativeWindowHandle) override;
            void Resize(uint32 width, uint32 height) override;
            NativeWindowHandle GetNativeWindow() override;
    };
}

#endif