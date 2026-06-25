#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
#find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

#add_library(ConsoleWindow STATIC
#  Private/ConsoleWindow.cpp
#  Public/ConsoleWindow.h
#  Public/QtConsoleWindow.h
#  Private/QtConsoleWindow.cpp
#)

#target_link_libraries(ConsoleWindow PRIVATE 
#  XYBCore
#  Qt${QT_VERSION_MAJOR}::Widgets
#)

#target_compile_definitions(ConsoleWindow PRIVATE CONSOLEWINDOW_LIBRARY)


xyb_glob_cpp_sources(XYBCORE_SOURCES DIRS 
    Core/Private 
    QtBackend/ConsoleWindow/Private
)

add_library(XYBEditor
    ${XYBCORE_SOURCES}
    QtBackend/ConsoleWindow/Public/QtConsoleWindow.h
    QtBackend/ConsoleWindow/Public/QtConsoleWindow.ui
)

set_target_properties(XYBEditor PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/QtBackend/ConsoleWindow/Public"
)

target_link_libraries(XYBEditor PUBLIC
    XYBCore
    Qt${QT_VERSION_MAJOR}::Widgets
)

target_include_directories(XYBEditor PUBLIC
    Core/Public 
    QtBackend/ConsoleWindow/Public
)