cmake_minimum_required(VERSION 2.8.0)
aux_source_directory(. TST_LIST)
add_definitions(-std=c++11)

find_package(GTest REQUIRED)
find_package(Threads)
include_directories(${GTEST_INCLUE_DIRS})
include_directories(${PROJECT_BINARY_DIR}/include)
include_directories(../../src/binarysearch)

add_executable(binary_search_test ${TST_LIST})
target_link_libraries(binary_search_test ${GTEST_BOTH_LIBRARIES})
target_link_libraries(binary_search_test ${CMAKE_THREAD_LIBS_INIT})

enable_testing()
add_test(NAME TestBinarySearch COMMAND binary_search_test)
 