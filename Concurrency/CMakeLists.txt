cmake_minimum_required(VERSION 3.6)
project(fivt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_executable(fivt ${SOURCE_FILES} readme.txt)

add_subdirectory(task-1-A)
add_subdirectory(task-1-B)
add_subdirectory(task-1-E)


