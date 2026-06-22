message("-----------开始构建 XYBEngine 主项目 FirstDemo------------")
 
#XYB_LIB_BUILD
add_executable(XYBGame
    TestApplication.h
    main.cpp
)



target_link_libraries(XYBGame PRIVATE
    XYBCore
)