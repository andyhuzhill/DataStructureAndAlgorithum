aux_source_directory(. DLIST_FILES)
add_library(dlist ${DLIST_FILES})
install(FILES dlist.h DESTINATION ${PROJECT_BINARY_DIR}/include)