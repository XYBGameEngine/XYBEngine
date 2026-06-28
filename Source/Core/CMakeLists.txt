# Core 模块 CMake 配置
# 构建 XYBCore 静态库：基础类型、日志门面（spdlog）及模块接口定义

xyb_glob_cpp_sources(XYBCORE_SOURCES DIRS Private)

add_library(XYBCore ${XYBCORE_SOURCES})

target_include_directories(XYBCore PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public  
)

target_link_libraries(XYBCore PUBLIC
    spdlog
)
