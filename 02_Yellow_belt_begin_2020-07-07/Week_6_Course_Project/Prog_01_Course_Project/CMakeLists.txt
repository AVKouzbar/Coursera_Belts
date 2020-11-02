cmake_minimum_required(VERSION 3.15)
project(Prog_01_Course_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Prog_01_Course_Project main.cpp date.cpp database.cpp condition_parser.cpp node.cpp token.cpp events.h events.cpp condition_parser_test.cpp test_storage.h)