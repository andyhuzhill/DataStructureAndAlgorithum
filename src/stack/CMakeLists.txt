aux_source_directory(. STACK_FILES)
include_directories(../list)
add_library(stack ${STACK_FILES})
install(FILES stack.h DESTINATION ${PROJECT_BINARY_DIR}/include)