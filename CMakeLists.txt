# Cmake 引擎构架
cmake_minimum_required(VERSION 3.20)

project(XYBEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
include(XYBHelpers)

add_subdirectory(Source/Core) 
add_subdirectory(ThirdParty/SPDLog)

message("-----------开始构建 XYBEngine 主项目 FirstDemo------------")
 
#XYB_LIB_BUILD
add_executable(XYBGame 
    Samples/FirstDemo/main.cpp
)  

target_link_libraries(XYBGame PRIVATE 
    XYBCore 
)