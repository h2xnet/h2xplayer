cmake_minimum_required(VERSION 3.5)

# project name
project(h2xbase LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR})

# add defined
add_definitions(-D H2XCOMPONENT_BUILD)
add_definitions(-D WIN32)
add_definitions(-D H2XBASE_IMPLENT)

set(h2xbase_h2xbase_HEADERS
        h2xbase_export.h
    )

set(h2xbase_h2xbase_SOURCES
        h2xbase_dll.cpp
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

