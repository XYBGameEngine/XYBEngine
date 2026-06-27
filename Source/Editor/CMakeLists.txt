xyb_glob_cpp_sources(XYBCORE_SOURCES DIRS 
    Core/Private 
    QtBackend/Application/Private
    QtBackend/ConsoleWindow/Private
)

add_library(XYBEditor STATIC
    ${XYBCORE_SOURCES}
    QtBackend/ConsoleWindow/Public/QtConsoleWindow.h
    QtBackend/ConsoleWindow/Public/QtConsoleWindow.ui
)

set_target_properties(XYBEditor PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/QtBackend/ConsoleWindow/Public"
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
)