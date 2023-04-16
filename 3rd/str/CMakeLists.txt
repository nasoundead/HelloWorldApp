
# SET(LIBRARY_OUTPUT_DIRECTORY ${PRPJECT_SOURCE_DIR}/lib)

set(lib_name str)

# include_directories(header-dir) 是一个全局包含，向下传递。什么意思呢？
# 就是说如果某个目录的 CMakeLists.txt 中使用了该指令，其下所有的子目录默认也包含了header-dir 目录。
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)
# target_include_directories(${lib_name} ./)

# 库文件
add_library(${lib_name} SHARED str.c)

# test
add_executable(strtest str_test.c)
target_link_libraries(strtest ${lib_name})

add_test(
    NAME strtest
    COMMAND $<TARGET_FILE:strtest>#
)