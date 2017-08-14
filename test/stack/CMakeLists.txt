cmake_minimum_required(VERSION 2.8.0)
aux_source_directory(. TST_LIST)
aux_source_directory(.. SRC_LIST)
aux_source_directory(../../list LST_SRC)
add_definitions(-std=c++11)

enable_testing()
find_package(GTest REQUIRED)
find_package(Threads)
include_directories(${GTEST_INCLUE_DIRS})
include_directories(../../src/list)
include_directories(../../src/stack)

add_executable(stack_test ${SRC_LIST} ${TST_LIST} ${LST_SRC})
target_link_libraries(stack_test ${GTEST_BOTH_LIBRARIES})
target_link_libraries(stack_test ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(stack_test ${PROJECT_BINARY_DIR}/lib/liblist.a)
target_link_libraries(stack_test ${PROJECT_BINARY_DIR}/lib/libstack.a)

add_test(NAME TestStack COMMAND stack_test)

