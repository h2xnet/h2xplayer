cmake_minimum_required(VERSION 3.5)

project(h2xplayer LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add defined
add_definitions(-D H2XCOMPONENT_BUILD)
add_definitions(-D WIN32)
add_definitions(-D H2XBASE_IMPLENT)
add_definitions(-D H2XCORE_IMPLENT)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

#file(GLOB QML_SRC_LIST "*.qml")
#ADD_CUSTOM_TARGET(h2xplayer ${QML_SRC_LIST})

# include path
include_directories(${PROJECT_SOURCE_DIR}/)
include_directories(${PROJECT_SOURCE_DIR}/../)
include_directories(${PROJECT_SOURCE_DIR}/../../)
include_directories(${PROJECT_SOURCE_DIR}/../../include/)

if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
    #debug
    message(STATUS "current build model debug")

    include_directories(${PROJECT_SOURCE_DIR}/../../libs/Debug/)

elseif(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Release"))
    #release
    message(STATUS "current build model release")

    include_directories(${PROJECT_SOURCE_DIR}/../../libs/Release/)

else()
    #other

    message("include path build type is not Debug and Release")

endif()

# include libffmpeg
include_directories(${PROJECT_SOURCE_DIR}/../)
include_directories(${PROJECT_SOURCE_DIR}../../)
include_directories(${PROJECT_SOURCE_DIR}../../../)

if (CMAKE_CL_64)
    #x64
    message(STATUS "current build model x64 arch")

    #libffmpeg
    include_directories(${PROJECT_SOURCE_DIR}/../../depend/libffmpeg/x64/include/)
    link_directories(${PROJECT_SOURCE_DIR}/../../depend/libffmpeg/x64/lib/)

else(CMAKE_CL_64)
    #x86
    message(STATUS "current build model x64 arch")

    #libffmpeg
    include_directories(${PROJECT_SOURCE_DIR}/../../depend/libffmpeg/x64/include/)
    link_directories(${PROJECT_SOURCE_DIR}/../../depend/libffmpeg/x86/lib/)

endif(CMAKE_CL_64)

# library path
if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
    #debug
    link_directories(${CMAKE_BINARY_DIR}/Debug/)

elseif(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Release"))
    #release
    link_directories(${CMAKE_BINARY_DIR}/Release/)

else()
    #other

    message("library path build type is not Debug and Release")

endif()

# library fileName
link_libraries(h2xbase.lib)
link_libraries(h2xcore.lib)

# library libffmpeg
link_libraries(avcodec.lib)
link_libraries(avdevice.lib)
link_libraries(avfilter.lib)
link_libraries(avformat.lib)
link_libraries(avutil.lib)
link_libraries(postproc.lib)
link_libraries(swresample.lib)
link_libraries(swscale.lib)

# header file list
set(h2xplayer_HEADERS
        app.h
        src/cache/database_cache.h
        src/cache/file_cache.h
        src/plugins/video_player/video_player.h
        src/runmgr/application_run_manager.h
    )

# source file list
set(h2xplayer_SOURCES
        main.cpp
        app.cpp
        src/cache/database_cache.cpp
        src/cache/file_cache.cpp
        src/plugins/video_player/video_player.cpp
        src/runmgr/application_run_manager.cpp
    )

find_package(Qt5 COMPONENTS Core Quick Sql REQUIRED)


if(ANDROID)
    add_library(h2xplayer SHARED
      ${h2xplayer_HEADERS} ${h2xplayer_SOURCES}
      #main.cpp
      qml.qrc
    )
else()
    add_executable(h2xplayer
      ${h2xplayer_HEADERS} ${h2xplayer_SOURCES}
      #main.cpp
      qml.qrc
    )
endif()

target_compile_definitions(h2xplayer
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_libraries(h2xplayer PRIVATE Qt5::Core Qt5::Quick Qt5::Sql)
#target_link_libraries(h2xplayer Qt5::Core Qt5::Quick Qt5::Sql)
