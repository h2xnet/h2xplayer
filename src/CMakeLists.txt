# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("h2xplayer")

# 包含子项目。

# set all project output path
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")

# base library project
add_subdirectory("h2xbase")

# micro kernel library project
add_subdirectory("h2xcore")

# extend plugin share library project list
#add_subdirectory("h2xextend")

# h2xplayer : ui application program project
add_subdirectory("h2xplayer")



