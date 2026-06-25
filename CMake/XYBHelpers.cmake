# 收集指定目录下的 .cpp 源文件
# 用法:
#   xyb_glob_cpp_sources(out_var DIRS Private)
#   xyb_glob_cpp_sources(out_var DIRS Private Utils RECURSE)
function(xyb_glob_cpp_sources out_var)
    cmake_parse_arguments(ARG "RECURSE" "" "DIRS" ${ARGN})

    if(NOT ARG_DIRS)
        message(FATAL_ERROR "xyb_glob_cpp_sources: 必须指定 DIRS 目录列表")
    endif()

    set(_sources)
    foreach(_dir IN LISTS ARG_DIRS)
        if(IS_ABSOLUTE "${_dir}")
            set(_glob_dir "${_dir}")
        else()
            set(_glob_dir "${CMAKE_CURRENT_SOURCE_DIR}/${_dir}")
        endif()

        if(ARG_RECURSE)
            file(GLOB_RECURSE _dir_sources CONFIGURE_DEPENDS "${_glob_dir}/*.cpp")
        else()
            file(GLOB _dir_sources CONFIGURE_DEPENDS "${_glob_dir}/*.cpp")
        endif()
        list(APPEND _sources ${_dir_sources})
    endforeach()

    set(${out_var} "${_sources}" PARENT_SCOPE)
endfunction()
