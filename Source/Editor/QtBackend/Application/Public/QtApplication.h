// Copyright XYBEngine. All Rights Reserved.
//
// QtApplication.h - Qt 后端编辑器应用实现
//
// 模块：Editor / QtBackend
// 职责：IEditorApplication 的 Qt 实现，封装 QApplication 生命周期。

#ifndef QTAPPLICATION_H
#define QTAPPLICATION_H

#include "Core.h"
#include <QApplication>
#include "IEditorApplication.h"

namespace XYBEngine
{ 
    /**
     * Qt 编辑器应用。
     *
     * 持有 QApplication 实例；Run() 调用 exec() 进入 Qt 事件循环。
     */
    class XYB_API QtApplication : public IEditorApplication
    {
    private: 
        UniquePtr<QApplication> g_qtApplication;
    public:
        void Initialize(int argc, char** argv) override;
        void Run() override;
        void Shutdown() override;
    };

}
#endif // QTAPPLICATION_H