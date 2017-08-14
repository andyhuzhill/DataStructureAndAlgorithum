aux_source_directory(. BUBBLE_SORT_FILES)
add_library(bubblesort ${BUBBLE_SORT_FILES})
install(FILES bubble_sort.h DESTINATION ${PROJECT_BINARY_DIR}/include)