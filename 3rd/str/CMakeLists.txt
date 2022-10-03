
# SET(LIBRARY_OUTPUT_DIRECTORY ${PRPJECT_SOURCE_DIR}/lib)

set(lib_name str)
include_directories(../include/)

# 库文件
add_library(${lib_name} SHARED str.c)

# test
add_executable(strtest str_test.c)
target_link_libraries(strtest ${lib_name})

add_test(
    NAME strtest
    COMMAND $<TARGET_FILE:strtest>#
)