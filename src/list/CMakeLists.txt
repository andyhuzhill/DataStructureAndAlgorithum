aux_source_directory(. LIST_FILES)
add_library(list ${LIST_FILES})
install(FILES list.h DESTINATION ${PROJECT_BINARY_DIR}/include)