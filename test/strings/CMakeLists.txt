cmake_minimum_required(VERSION 2.8.0)
aux_source_directory(. TST_LIST)
aux_source_directory(.. SRC_LIST)
add_definitions(-std=c++11)

enable_testing()
find_package(GTest REQUIRED)
find_package(Threads)
include_directories(${GTEST_INCLUE_DIRS})
include_directories(../../src/strings)

add_executable(string_test ${SRC_LIST} ${TST_LIST})
target_link_libraries(string_test ${GTEST_BOTH_LIBRARIES})
target_link_libraries(string_test ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(string_test ${PROJECT_BINARY_DIR}/lib/libstrings.a)

add_test(NAME TestStrings COMMAND string_test)

