add_library(XYBCore 
    Private/ModuleManager.cpp
    Private/Engine.cpp 
    Private/LogModule.cpp
)

target_compile_definitions(XYBCore PRIVATE XYB_LIB_BUILD)

target_include_directories(XYBCore PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)