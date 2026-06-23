add_library(XYBCore 
    Private/Log.cpp 
)

target_include_directories(XYBCore PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public  
)

target_link_libraries(XYBCore PUBLIC
    spdlog
)