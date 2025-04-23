cmake_minimum_required(VERSION 3.10)
project(checkers)
include_directories(include)
add_executable(checkers src/main.cpp src/board.cpp src/checkers_except.cpp)
