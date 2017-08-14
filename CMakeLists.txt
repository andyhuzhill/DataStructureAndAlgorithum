cmake_minimum_required(VERSION 2.8)

set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# Data Structures
add_subdirectory(src/list)
add_subdirectory(src/dlist)
add_subdirectory(src/stack)

# Algorithms 
add_subdirectory(src/sort/bubble_sort)
add_subdirectory(src/sort/insert_sort)
add_subdirectory(src/binarysearch)

add_subdirectory(src/strings)

# Add test project
enable_testing()
add_subdirectory(test/list)
add_subdirectory(test/dlist)
add_subdirectory(test/stack)

# Algorithms 
add_subdirectory(test/sort/bubble_sort)
add_subdirectory(test/sort/insert_sort)
add_subdirectory(test/binarysearch)

add_subdirectory(test/strings)

