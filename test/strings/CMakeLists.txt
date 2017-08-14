project(string_test)
cmake_minimum_required(VERSION 2.8.0)
aux_source_directory(. TST_LIST)
aux_source_directory(.. SRC_LIST)
add_definitions(-std=c++11)

enable_testing()
find_package(GTest REQUIRED)
find_package(Threads)
include_directories(${GTEST_INCLUE_DIRS})

add_executable(${PROJECT_NAME} ${SRC_LIST} ${TST_LIST})
target_link_libraries(${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})

add_test(AllTestInList ${PROJECT_NAME})

