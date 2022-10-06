# SET(EXECUTABLE_OUTPUT_DIRECTORY ${PRPJECT_BINARY_DIR}/bin)
#获取年月日时分秒
string(TIMESTAMP COMPILE_TIME %Y%m%d%H%M%S)
message(STATUS "compile time:${COMPILE_TIME}")

message(STATUS "CMAKE_BINARY_DIR:${CMAKE_BINARY_DIR}")
# add the executable
ADD_EXECUTABLE(struct_init struct_init.c)



