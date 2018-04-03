cmake_minimum_required(VERSION 3.6)
project(task_7_A)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES solution.h)
add_executable(task_7_A ${SOURCE_FILES})