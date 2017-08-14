cmake_minimum_required(VERSION 2.8.0)
aux_source_directory(. TST_LIST)
aux_source_directory(../../src/list SRC_LIST)
aux_source_directory(../../src/stack LST_SRC)
add_definitions(-std=c++11)

find_package(GTest REQUIRED)
find_package(Threads)
include_directories(${GTEST_INCLUE_DIRS})
include_directories(../../src/list)
include_directories(../../src/stack)

add_executable(stack_test ${SRC_LIST} ${TST_LIST} ${LST_SRC})
target_link_libraries(stack_test ${GTEST_BOTH_LIBRARIES})
target_link_libraries(stack_test ${CMAKE_THREAD_LIBS_INIT})

enable_testing()
add_test(NAME TestStack COMMAND stack_test)

