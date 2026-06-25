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

# 将 MinGW 运行时与 Qt 依赖 DLL 复制到可执行文件目录（仅 Windows + MinGW）
# 用法: xyb_deploy_windows_runtime(TARGET XYBGame)
function(xyb_deploy_windows_runtime target)
    if(NOT WIN32 OR NOT MINGW)
        return()
    endif()

    get_filename_component(_mingw_bin_dir "${CMAKE_CXX_COMPILER}" DIRECTORY)
    set(_mingw_runtime_dlls
        libgcc_s_seh-1.dll
        libstdc++-6.dll
        libwinpthread-1.dll
    )

    foreach(_dll IN LISTS _mingw_runtime_dlls)
        add_custom_command(TARGET ${target} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${_mingw_bin_dir}/${_dll}"
                "$<TARGET_FILE_DIR:${target}>"
            COMMENT "Deploy MinGW runtime: ${_dll}"
        )
    endforeach()

    if(TARGET Qt6::windeployqt)
        add_custom_command(TARGET ${target} POST_BUILD
            COMMAND "$<TARGET_FILE:Qt6::windeployqt>"
                --no-translations
                "$<TARGET_FILE:${target}>"
            COMMENT "Deploy Qt libraries for ${target}"
        )
    endif()
endfunction()
