// Copyright XYBEngine. All Rights Reserved.
//
// QtApplication.cpp - Qt 编辑器应用实现

#include "QtApplication.h"

namespace XYBEngine
{     
    /** 注册 Qt 应用实现到 EditorApplicationRegister */
    void QtApplicationResiter()
    {
        EditorApplicationRegister::GetInstance().Register(MakeShared<QtApplication>());
    }
    
    void QtApplication::Initialize(int argc, char** argv)
    {
        // 避免重复创建：若外部已存在 QApplication 实例则复用
        if (!QApplication::instance())
        {
            g_qtApplication = std::make_unique<QApplication>(argc, argv);
        }
    }

    void QtApplication::Run()
    {
        if (auto* app = qobject_cast<QApplication*>(QCoreApplication::instance()))
        {
            app->exec(); // 阻塞，直到最后一个窗口关闭或 quit()
        } 
    }

    void QtApplication::Shutdown()
    {
        // 预留：后续可在此释放全局 Qt 资源、断开信号槽等
    } 
}