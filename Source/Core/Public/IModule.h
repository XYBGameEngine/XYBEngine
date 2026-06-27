// Copyright XYBEngine. All Rights Reserved.
//
// IModule.h - 引擎模块生命周期接口
//
// 模块：Core
// 职责：定义模块的标准启动/关闭契约。后续各功能模块（Render、Editor 等）
//       可继承此接口，由模块管理器统一调度 Startup / Shutdown。

#ifndef MODULE_H
#define MODULE_H

#include "Core.h"

namespace XYBEngine
{
    /**
     * 引擎模块基类接口。
     *
     * 生命周期：Startup() → （运行期）→ Shutdown()
     */
    class XYB_API IModule
    {
    public:
        IModule() = default;
        ~IModule() = default;
    public:
        /** 模块名称，用于日志与调试 */
        virtual const char* GetName() const = 0;
        /** 模块初始化，在引擎启动阶段调用 */
        virtual void Startup() = 0;
        /** 模块清理，在引擎关闭阶段调用 */
        virtual void Shutdown() = 0;
    };
}

#endif