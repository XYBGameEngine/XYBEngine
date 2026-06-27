// Copyright XYBEngine. All Rights Reserved.
//
// ConsoleWindow.h - 控制台窗口（IEditorWindow 门面）
//
// 模块：Editor / QtBackend / ConsoleWindow
// 职责：对外暴露 IEditorWindow 接口，内部委托 QtConsoleWindow 完成实际 UI。

#ifndef CONSOLEWINDOW_H
#define CONSOLEWINDOW_H

#include "Core.h"
#include "IEditorWindow.h"
#include "QtConsoleWindow.h" 

namespace XYBEngine
{ 
    /**
     * 控制台窗口门面类。
     *
     * 隔离 Qt 细节：调用方只依赖 IEditorWindow，无需包含 Qt 头文件。
     */
    class XYB_API ConsoleWindow : public IEditorWindow
    {
        private:
            UniquePtr<QtConsoleWindow> m_consoleWindow; 
        public:  
            ~ConsoleWindow();

            void Show() override;

            void Hide() override;
            
            void Close() override; 
    };
}
#endif // CONSOLEWINDOW_H