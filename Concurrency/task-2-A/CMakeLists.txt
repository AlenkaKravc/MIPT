cmake_minimum_required(VERSION 3.6)
project(task_2_A)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES solution.h)
add_executable(task_2_A ${SOURCE_FILES})