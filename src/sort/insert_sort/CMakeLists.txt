aux_source_directory(. INSERT_SORT_FILES)
add_library(insertsort ${INSERT_SORT_FILES})
install(FILES insert_sort.h DESTINATION ${PROJECT_BINARY_DIR}/include)