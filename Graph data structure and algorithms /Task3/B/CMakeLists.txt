cmake_minimum_required(VERSION 3.6)
project(Transformations)

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "${CCACHE_PROGRAM}")
    set(GLOBAL_CMAKE_CCACHE_RULES -DCMAKE_C_COMPILER=/usr/lib/ccache/cc -DCMAKE_CXX_COMPILER=/usr/lib/ccache/c++)
    set(GLOBAL_CCACHE_ENV -DCMAKE_C_COMPILER=/usr/lib/ccache/cc -DCMAKE_CXX_COMPILER=/usr/lib/ccache/c++)
endif(CCACHE_PROGRAM)


set(SOURCE_FILES transformation.cpp transformation.h)

set(SOURCE_FILES_TEST transformation.cpp transformation.h transformation_test.cpp transformation_test.h)
add_executable(Transformations main.cpp ${SOURCE_FILES})

add_subdirectory(libgoogletest/googletest)
include_directories(libgoogletest/googletest/include)

add_executable(RunTest transformation_test.cpp ${SOURCE_FILES})
target_link_libraries(RunTest ${GTEST_LIBRARIES} gtest gtest_main)