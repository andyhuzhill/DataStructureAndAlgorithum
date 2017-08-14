cmake_minimum_required(VERSION 2.8.0)
aux_source_directory(. TST_LIST)
aux_source_directory(../../src/dlist SRC_LIST)
add_definitions(-std=c++11)

find_package(GTest REQUIRED)
find_package(Threads)
include_directories(${GTEST_INCLUE_DIRS})
include_directories(../../src/dlist)

add_executable(dlist_test ${SRC_LIST} ${TST_LIST})
target_link_libraries(dlist_test ${GTEST_BOTH_LIBRARIES})
target_link_libraries(dlist_test ${CMAKE_THREAD_LIBS_INIT})

enable_testing()
add_test(NAME TestDList COMMAND dlist_test)
