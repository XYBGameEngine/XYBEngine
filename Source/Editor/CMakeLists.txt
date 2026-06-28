xyb_glob_cpp_sources(XYBCORE_SOURCES DIRS 
    Core/Private 
    QtBackend/Application/Private
    QtBackend/ConsoleWindow/Private
    QtBackend/MainWindow/Private
)

add_library(XYBEditor
    ${XYBCORE_SOURCES}    
    QtBackend/ConsoleWindow/Public/QtConsoleWindow.h 
    QtBackend/MainWindow/Public/QtMainWindow.h 
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
    QtBackend/ConsoleWindow/Public
    QtBackend/MainWindow/Public
)