
cmake_minimum_required(VERSION 3.5)
project(INVADER)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_INCLUDE_CURRENT_DIR TRUE)
file(GLOB SOURCES "*.cpp")

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

find_package(SDL2 REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O4")

add_executable(Invader ${SOURCES})
target_link_libraries(Invader ${SDL2_LIBRARIES} SDL2_image SDL2_ttf SDL2_mixer)
