cmake_minimum_required(VERSION 3.6)
project(task_5_A)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp solution.h)
add_executable(task_5_A ${SOURCE_FILES})