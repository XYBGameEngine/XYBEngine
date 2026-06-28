// Copyright XYBEngine. All Rights Reserved.
//
// Core.h - 引擎核心基础类型与导出宏
//
// 模块：Core
// 职责：提供跨模块共享的基础类型别名、智能指针封装及 DLL 导出宏（XYB_API）。
//       所有引擎模块均应包含此头文件，而非直接使用 std 类型。

#pragma once

#include <cstdint>
#include <memory>
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>

// ---------------------------------------------------------------------------
// 导出宏：静态链接时 XYB_API 为空；动态库构建时按平台展开为 dllexport/dllimport
// ---------------------------------------------------------------------------
#if defined(XYB_SHARED_BUILD)
    #if defined(_WIN32)
        #if defined(XYB_LIB_BUILD)
            #define XYB_API __declspec(dllexport)
        #else
            #define XYB_API __declspec(dllimport)
        #endif
    #else
        #define XYB_API __attribute__((visibility("default")))
    #endif
#else
    #define XYB_API
#endif

namespace XYBEngine
{
    // 固定宽度整数类型（与平台无关，便于序列化与跨平台协议）
    using int8   = std::int8_t;
    using int16  = std::int16_t;
    using int32  = std::int32_t;
    using int64  = std::int64_t;

    using uint8  = std::uint8_t;
    using uint16 = std::uint16_t;
    using uint32 = std::uint32_t;
    using uint64 = std::uint64_t;

    using String = std::string;
    
    template<class T>
    using UniquePtr = std::unique_ptr<T>;

    template<class T, class... Args>
    UniquePtr<T> MakeUnique(Args&&... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<class T>
    using SharedPtr = std::shared_ptr<T>;

    template<class T, class... Args>
    SharedPtr<T> MakeShared(Args&&... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    template<class T>
    using WeakPtr = std::weak_ptr<T>;

    template<class T>
    using UniqueVectorPtr = std::vector<UniquePtr<T>>;

    template<class T1, class T2>
    using UnOrderedMap = std::unordered_map<T1, T2>;

    template<class T1, class T2>
    using OrderedMap = std::map<T1, T2>;
 
} 
