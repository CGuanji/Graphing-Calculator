cmake_minimum_required(VERSION 3.16)
project(Graphing)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Graphing)
include_directories(where_is_my_working_folder)

add_executable(Graphing
        Graphing/Animate.app/Contents/MacOS/Animate
        Graphing/Animate.app/Contents/Resources/empty.lproj
        Graphing/Animate.app/Contents/Info.plist
        Graphing/Animate.app/Contents/PkgInfo
        Graphing/_qmake.stash
        Graphing/animate
        Graphing/animate.cpp
        Graphing/animate.h
        Graphing/constants.h
        Graphing/description.h
        Graphing/graph_info.cpp
        Graphing/graph_info.h
        Graphing/Graphing.pro
        Graphing/main.cpp
        Graphing/plot.cpp
        Graphing/plot.h
        Graphing/random.cpp
        Graphing/random.h
        Graphing/sidebar.cpp
        Graphing/sidebar.h
        Graphing/system.cpp
        Graphing/system.h
        where_is_my_working_folder/Where_is_my_working_folder/main.cpp
        where_is_my_working_folder/arial.ttf
        "where_is_my_working_folder/Font Problem.png"
        where_is_my_working_folder/FONT_INSTRUCTIONS_FOR_WINDOWS.txt
        where_is_my_working_folder/Roboto-Thin.ttf
        arial.ttf
        CMakeLists.txt
        "Font Problem.png"
        FONT_INSTRUCTIONS_FOR_WINDOWS.txt
        Roboto-Thin.ttf
        "Single Bouncing Ball.png")
