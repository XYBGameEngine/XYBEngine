# Editor 模块 CMake 配置
# 构建 XYBEditor 静态库：Core 抽象层 + Qt 后端（Application / MainWindow / ConsoleWindow）
# UI 布局文件位于 QtBackend/ui，由 AUTOUIC 自动生成 ui_*.h

xyb_glob_cpp_sources(XYBCORE_SOURCES DIRS 
    Core/Private 
    QtBackend/Application/Private
    QtBackend/Panel/Private 
    QtBackend/Shell/Private 
)

add_library(XYBEditor
    ${XYBCORE_SOURCES}    
    QtBackend/Panel/Public/QtConsolePanel.h 
    QtBackend/Shell/Public/QtMainWindow.h 
)

set_target_properties(XYBEditor PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTOUIC_SEARCH_PATHS 
        "${CMAKE_CURRENT_SOURCE_DIR}/QtBackend/ui" 
)

target_link_libraries(XYBEditor PRIVATE
    XYBCore
    Qt${QT_VERSION_MAJOR}::Widgets
)

target_include_directories(XYBEditor PUBLIC
    Core/Public 
    PRIVATE
    QtBackend/Application/Public
    QtBackend/Panel/Public
    QtBackend/Shell/Public
)
