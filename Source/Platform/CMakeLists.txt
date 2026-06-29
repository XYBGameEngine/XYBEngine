xyb_glob_cpp_sources(XYBPLATFORM_SOURCES DIRS   
    Windows/Private
)

add_library(XYBPlatform
    ${XYBPLATFORM_SOURCES}
)

target_link_libraries(XYBPlatform PRIVATE
    XYBCore 
)

target_include_directories(XYBPlatform PRIVATE
    Public/
    Windows/Public
)