// Copyright XYBEngine. All Rights Reserved.
//
// QtFactory.cpp - Qt 编辑器工厂实现与自动注册
//
// 静态注册说明：
//   s_qtFactoryRegistration 在程序启动、本翻译单元加载时构造，
//   将 QtFactory 注册到 CreateEditorFactory，无需手动调用注册代码。

#include "QtFactory.h" 
#include "QtApplication.h"
#include "ConsoleWindow.h"

namespace XYBEngine
{
    /** 利用静态对象构造顺序，在 main 之前完成工厂注册 */
    struct QtFactoryRegistration
    {
        QtFactoryRegistration()
        {
            CreateEditorFactory::GetInstance().RegisterEditorFactory(EditorApplicationBackend::Qt, MakeShared<QtFactory>());
            Log::GetInstance().LogInfo("QtFactory registered");
        }
    };
    static QtFactoryRegistration s_qtFactoryRegistration;
 
    QtFactory::~QtFactory()
    {
    }

    SharedPtr<IEditorWindow> QtFactory::CreateEditorWindow(EditorWindowType type)
    {
        switch (type)
        { 
        case EditorWindowType::ConsoleWindow:
            return MakeShared<ConsoleWindow>();
        default:
            XYB_LOG_ERROR("Invalid editor window type");
            return nullptr;
        }
    }

    SharedPtr<IEditorApplication> QtFactory::CreateEditorApplication()
    {
        return MakeShared<QtApplication>();
    }
}