add_library(XYBRuntime
    Private/Engine.cpp
    Private/LogModule.cpp
    Private/ModuleManager.cpp
    Private/IApplication.cpp
)

target_include_directories(XYBRuntime PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

target_link_libraries(XYBRuntime PRIVATE
    XYBCore
)