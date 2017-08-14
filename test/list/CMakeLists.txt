cmake_minimum_required(VERSION 2.8.0)
aux_source_directory(. TST_LIST)
aux_source_directory(../../src/list SRC_LIST)
add_definitions(-std=c++11)

find_package(GTest REQUIRED)
find_package(Threads)
include_directories(${GTEST_INCLUE_DIRS})
include_directories(../../src/list)

add_executable(list_test ${SRC_LIST} ${TST_LIST})
target_link_libraries(list_test ${GTEST_BOTH_LIBRARIES})
target_link_libraries(list_test ${CMAKE_THREAD_LIBS_INIT})

enable_testing()
add_test(NAME TestList COMMAND list_test)