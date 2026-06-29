#include "WindowsNativeWindow.h"

namespace XYBEngine
{ 
    WindowsNativeWindow::~WindowsNativeWindow()
    {  
    }

    uint32 WindowsNativeWindow::GetWidth()
    {
        return m_width;
    }

    uint32 WindowsNativeWindow::GetHeight()
    {
        return m_height;
    }

    void WindowsNativeWindow::Create(NativeWindowHandle nativeWindowHandle)
    {
        m_nativeWindowHandle = nativeWindowHandle;
    }

    void WindowsNativeWindow::Resize(uint32 width, uint32 height)
    {
        m_width = width;
        m_height = height; 
    }

    NativeWindowHandle WindowsNativeWindow::GetNativeWindow()
    { 
        return m_nativeWindowHandle;
    }
}