cmake_minimum_required(VERSION 3.6)
project(task_4_A)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp solution.h)
add_executable(task_4_A ${SOURCE_FILES})