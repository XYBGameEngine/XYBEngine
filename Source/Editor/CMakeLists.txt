add_subdirectory(QtBackend/ConsoleWindow)

xyb_glob_cpp_sources(XYBCORE_SOURCES DIRS 
    Core/Private 
    QtBackend/ConsoleWindow/Private
)

add_library(XYBEditor
    ${XYBCORE_SOURCES}
)

target_link_libraries(XYBEditor PUBLIC
    ConsoleWindow
)

target_include_directories(XYBEditor PUBLIC
    Core/Public 
    QtBackend/ConsoleWindow/Public
)