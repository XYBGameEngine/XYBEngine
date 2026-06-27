// Copyright XYBEngine. All Rights Reserved.
//
// QtFactory.h - Qt 后端编辑器工厂
//
// 模块：Editor / QtBackend
// 职责：IEditorFactory 的 Qt 实现，负责创建 QtApplication 与各 Qt 编辑器窗口。
// 注册：见 QtFactory.cpp 中的静态注册（链接本模块即自动注册到 CreateEditorFactory）

#ifndef QTFACTORY_H
#define QTFACTORY_H

#include "Core.h"
#include "IEditorFactory.h"  
#include "Log.h" 
#include "CreateEditorFactory.h"

namespace XYBEngine
{
    /** Qt 后端的编辑器工厂，在模块加载时自动注册 */
    class QtFactory : public IEditorFactory
    {
    public:  
        ~QtFactory();

        SharedPtr<IEditorApplication> CreateEditorApplication() override;

        SharedPtr<IEditorWindow> CreateEditorWindow(EditorWindowType type) override;
    };
}       
#endif // QTFACTORY_H