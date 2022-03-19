cmake_minimum_required(VERSION 3.5)

# project name
project(h2xbase LANGUAGES CXX)

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
add_definitions(-D H2XBASE_IMPLENT)

set(h2xbase_h2xbase_HEADERS
        h2xbase_export.h
        file/file_util.h
        log/log.h
    )

set(h2xbase_h2xbase_SOURCES
        h2xbase_dll.cpp
        file/file_util.cpp
        log/log.cpp
    )

# add shared library
add_library(h2xbase SHARED ${h2xbase_h2xbase_HEADERS} ${h2xbase_h2xbase_SOURCES})

# add static library
#add_library(h2xbase STATIC ${h2xbase_h2xbase_HEADERS} ${h2xbase_h2xbase_SOURCES})

# set version
# version set library version, SOVERSION set API version
set_target_properties(h2xbase PROPERTIES version 1.0 SOVERSION 1)

#
SET_TARGET_PROPERTIES(h2xbase PROPERTIES LINKER_LANGUAGE C)

target_link_libraries(h2xbase PRIVATE Qt5::Core)

target_compile_definitions(h2xbase PRIVATE H2XBASE_LIBRARY)
