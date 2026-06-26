# Cmake 引擎构架
cmake_minimum_required(VERSION 3.20)

project(XYBEngine)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
include(XYBHelpers)

# 添加资源文件
set(RESOURCE_FILES ${PROJECT_SOURCE_DIR}/UIResource/Resource.qrc)

add_subdirectory(Source/Core) 
add_subdirectory(ThirdParty/SPDLog)
add_subdirectory(Source/Editor) 

message("-----------开始构建 XYBEngine 主项目 FirstDemo------------")
 
#XYB_LIB_BUILD
add_executable(XYBGame 
    Samples/FirstDemo/main.cpp
    ${RESOURCE_FILES}
)

set_target_properties(XYBGame PROPERTIES AUTORCC ON)

target_link_libraries(XYBGame PRIVATE 
    XYBCore 
    XYBEditor
)

xyb_deploy_windows_runtime(XYBGame)