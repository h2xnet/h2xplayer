cmake_minimum_required(VERSION 3.5)

# project name
project(h2xcore  LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core REQUIRED)

include_directories(${CMAKE_SOURCE_DIR})

# add defined
add_definitions(-D H2XCOMPONENT_BUILD)
add_definitions(-D WIN32)
add_definitions(-D H2XCORE_IMPLENT)

set(h2xcore_h2xcore_HEADERS
        h2xcore_export.h
        application.h
    )

set(h2xcore_h2xcore_SOURCES
        h2xcore_dll.cpp
        application.cpp
    )

# add shared library
add_library(h2xcore SHARED ${h2xcore_h2xcore_HEADERS} ${h2xcore_h2xcore_SOURCES})

# add static library
#add_library(h2xcore STATIC ${h2xcore_h2xcore_HEADERS} ${h2xcore_h2xcore_SOURCES})

# set version
# version set library version, SOVERSION set API version
set_target_properties(h2xcore PROPERTIES version 1.0 SOVERSION 1)

#
SET_TARGET_PROPERTIES(h2xcore PROPERTIES LINKER_LANGUAGE C)

target_link_libraries(h2xcore PRIVATE Qt5::Core)

target_compile_definitions(h2xcore PRIVATE H2XCORE_LIBRARY)
