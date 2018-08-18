
cmake_minimum_required(VERSION 2.8.11)
project(INVADER)

set(CMAKE_INCLUDE_CURRENT_DIR TRUE)
file(GLOB SOURCES "*.cpp")

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(Invader ${SOURCES})
target_link_libraries(Invader ${CURSES_LIBRARIES})
