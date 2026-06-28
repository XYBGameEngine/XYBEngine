// Copyright XYBEngine. All Rights Reserved.
//
// IEditorApplication.h - 编辑器应用生命周期接口
//
// 模块：Editor / Core
// 职责：抽象编辑器宿主进程，与具体 UI 框架（Qt 等）解耦。
// 生命周期：Initialize → Run（阻塞主循环）→ Shutdown

#ifndef IEDITORAPPLICATION_H
#define IEDITORAPPLICATION_H

#include "Core.h"

namespace XYBEngine
{
    /**
     * 编辑器应用抽象接口。
     *
     * 实现类示例：QtApplication（封装 QApplication::exec）
     */
    class XYB_API IEditorApplication
    {
        public:
            virtual ~IEditorApplication() = default;

            /** 传入命令行参数，创建并初始化底层 UI 框架 */
            virtual void Initialize(int argc, char** argv) = 0;
            /** 进入主事件循环，直到应用退出 */
            virtual void Run() = 0;
            /** 释放资源，在 Run 返回后调用 */
            virtual void Shutdown() = 0;
    };

    class XYB_API EditorApplicationRegister
    {
        private:
            SharedPtr<IEditorApplication> m_editorApplication;
        public:
            static EditorApplicationRegister& GetInstance()
            {
                static EditorApplicationRegister s_instance;
                return s_instance;
            }

            void Register(SharedPtr<IEditorApplication> editorApplication);

            void UnRegister();

            SharedPtr<IEditorApplication> GetEditorApplication();
    };
}
#endif // IEDITORAPPLICATION_H