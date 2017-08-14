aux_source_directory(. STRINGS_FILES)
add_library(strings ${STRINGS_FILES})
install(FILES strings.h DESTINATION ${PROJECT_BINARY_DIR}/include)