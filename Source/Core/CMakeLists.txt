xyb_glob_cpp_sources(XYBCORE_SOURCES DIRS Private)

add_library(XYBCore ${XYBCORE_SOURCES})

target_include_directories(XYBCore PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public  
)

target_link_libraries(XYBCore PUBLIC
    spdlog
)