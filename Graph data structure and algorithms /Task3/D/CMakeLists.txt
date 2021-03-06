cmake_minimum_required(VERSION 3.6)
project(Substrings)

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "${CCACHE_PROGRAM}")
    set(GLOBAL_CMAKE_CCACHE_RULES -DCMAKE_C_COMPILER=/usr/lib/ccache/cc -DCMAKE_CXX_COMPILER=/usr/lib/ccache/c++)
    set(GLOBAL_CCACHE_ENV -DCMAKE_C_COMPILER=/usr/lib/ccache/cc -DCMAKE_CXX_COMPILER=/usr/lib/ccache/c++)
endif(CCACHE_PROGRAM)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Substrings.cpp Substrings.h)
set(SOURCE_FILES_TEST Substrings.cpp Substrings.h Substrings_test.cpp Substrings_test.h)
add_executable(Substrings main.cpp ${SOURCE_FILES})

add_subdirectory(libgoogletest/googletest)
include_directories(libgoogletest/googletest/include)

add_executable(RunTest Substrings_test.cpp  ${SOURCE_FILES})
target_link_libraries(RunTest ${GTEST_LIBRARIES} gtest gtest_main)