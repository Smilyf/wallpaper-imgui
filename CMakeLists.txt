


cmake_minimum_required(VERSION 3.0)

project(openglim)
set(openglim PROJECT_NAME)

set(CMAKE_CXX_STANDARD 20)
# 当使用 MSVC 编译器时, 设置输入代码的编码格式为 utf-8
if(MSVC)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D _CRT_SECURE_NO_WARNINGS /MP /utf-8")
endif(MSVC)

if (APPLE)
set(FLAG  "APPLE")
endif()

if (WIN32)
set(FLAG  "WIN32")
endif()

if (UNIX)
set(FLAG  "UNIX")
endif()
set(FLAG  "WIN32")
#set(FLAG  "UNIX")

set(OpenCV_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../opencv/build/x64/vc16/lib)
find_package(OpenCV REQUIRED)
# add header path
include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/../imgui
	${CMAKE_CURRENT_SOURCE_DIR}/../imgui/backends
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)


if (${FLAG} STREQUAL APPLE)
    # for <GLFW/glfw3.h>
    include_directories(
        /usr/local/include
        /opt/local/include
        /opt/homebrew/include
    )
endif()

# set common source
file(GLOB SRC
    ../imgui/*.cpp
    ../imgui/backends
)

# set specific source and other option for platform
if (${FLAG} STREQUAL WIN32)
    file (GLOB PLATFORM_SRC
        ../imgui/backends/imgui_impl_win32.*
        ../imgui/backends/imgui_impl_dx12.*
        ./src/win/main.cpp
    )
elseif (${FLAG} STREQUAL UNIX)
    # support both mac and linux
    add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GL3W)

  

    file (GLOB PLATFORM_SRC
        ../imgui/examples/libs/gl3w/GL/gl3w.*
        ../imgui/backends/imgui_impl_glfw.*
        ../imgui/backends/imgui_impl_opengl3.*
        ./src/linux/*.cpp
        ./src/linux/*.c
        
    )

endif()

# add link path
if (${FLAG} STREQUAL APPLE)
    link_directories(
        /usr/local/lib
        /opt/local/lib
        /opt/homebrew/lib
    )
endif()

# generate binary
add_executable(${PROJECT_NAME} ${SRC} ${PLATFORM_SRC})


# link lib, should install glfw first or prebuild lib and embed in project
if (${FLAG} STREQUAL WIN32)
    target_link_libraries(${PROJECT_NAME}
        d3d12.lib
        d3dcompiler.lib
        dxgi.lib
    )
elseif (${FLAG} STREQUAL APPLE)
    # mac: brew install glfw3
    find_library(OPENGL_LIBRARY OpenGL REQUIRED)
    find_library(COCOA_LIBRARY Cocoa REQUIRED)
    find_library(IOKIT_LIBRARY IOKit REQUIRED)
    find_library(COREVID_LIBRARY CoreVideo REQUIRED)
    message(${COCOA_LIBRARY})
    message(${IOKIT_LIBRARY})
    message(${COREVID_LIBRARY})

    target_link_libraries(${PROJECT_NAME}
        ${OPENGL_LIBRARY}
        ${COCOA_LIBRARY}
        ${IOKIT_LIBRARY}
        ${COREVID_LIBRARY}
        glfw # use this lib name
    )
elseif ((${FLAG} STREQUAL UNIX) AND NOT (${FLAG} STREQUAL APPLE))
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OpenCV_LIBS})
    target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw3.lib)
    
endif()

target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/lib/freetype.lib)
