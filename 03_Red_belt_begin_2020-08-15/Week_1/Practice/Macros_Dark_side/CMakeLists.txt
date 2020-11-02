cmake_minimum_required(VERSION 3.15)
project(Macros_Dark_side)

set(CMAKE_CXX_STANDARD 17)

add_executable(Macros_Dark_side main.cpp)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")