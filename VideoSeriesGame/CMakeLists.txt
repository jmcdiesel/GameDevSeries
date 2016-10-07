cmake_minimum_required(VERSION 3.6)

project(VideoSeriesGame)

# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIRS})
    link_libraries(${OPENGL_LIBRARIES})
endif()

set(SOURCE_FILES main.cpp Game.cpp Game.h EventHandler.cpp EventHandler.h Sprite.cpp Sprite.h GLSLProgram.cpp GLSLProgram.h ResourceManager.cpp ResourceManager.h)

add_executable(VideoSeriesGame ${SOURCE_FILES})
target_link_libraries(VideoSeriesGame ${SDL2_LIBRARY})