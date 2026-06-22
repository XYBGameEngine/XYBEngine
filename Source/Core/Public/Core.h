#pragma once

#include <cstdint>
#include <memory>
#include <iostream>
#include <vector>

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
    using int8   = std::int8_t;
    using int16  = std::int16_t;
    using int32  = std::int32_t;
    using int64  = std::int64_t;

    using uint8  = std::uint8_t;
    using uint16 = std::uint16_t;
    using uint32 = std::uint32_t;
    using uint64 = std::uint64_t;

    template<class T>
    using UniquePtr = std::unique_ptr<T>;

    template<class T>
    using SharedPtr = std::shared_ptr<T>;

    template<class T>
    using WeakPtr = std::weak_ptr<T>;

    template<class T>
    using UniqueVectorPtr = std::vector<UniquePtr<T>>;
} 
