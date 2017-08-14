cmake_minimum_required(VERSION 2.8.0)
aux_source_directory(. TST_LIST)
aux_source_directory(../../../src/sort/bubble_sort SRC_LIST)
add_definitions(-std=c++11)


find_package(GTest REQUIRED)
find_package(Threads)
include_directories(${GTEST_INCLUE_DIRS})
include_directories(../../../src/sort/bubble_sort)

add_executable(bubble_sort_test ${SRC_LIST} ${TST_LIST})
target_link_libraries(bubble_sort_test ${GTEST_BOTH_LIBRARIES})
target_link_libraries(bubble_sort_test ${CMAKE_THREAD_LIBS_INIT})

enable_testing()
add_test(NAME TestBubbleSort COMMAND bubble_sort_test)
