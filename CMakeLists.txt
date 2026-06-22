# Cmake 引擎构架
cmake_minimum_required(VERSION 3.20)

project(XYBEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Source) 
add_subdirectory(ThirdParty)

message("-----------开始构建 XYBEngine 主项目 FirstDemo------------")
 
#XYB_LIB_BUILD
add_executable(XYBGame
    Samples/FirstDemo/TestApplication.h
    Samples/FirstDemo/main.cpp
)  

target_link_libraries(XYBGame PRIVATE 
    XYBCore
)