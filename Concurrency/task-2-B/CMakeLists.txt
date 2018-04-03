cmake_minimum_required(VERSION 3.6)
project(task_2_B)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp solution_cv.h solution_semaphore.h)
add_executable(task_2_B ${SOURCE_FILES})