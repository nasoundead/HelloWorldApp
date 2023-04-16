
add_library(helloworld SHARED hello-world.c)

add_subdirectory(hello)

target_link_libraries(helloworld PRIVATE hello)

# PRIVATE：私有的。
# 生成 libhello-world.so时，只在 hello_world.c 中包含了 hello.h，libhello-world.so 对外的头文件——hello_world.h 中不包含 hello.h。
# 而且 main.c 不会调用 hello.c 中的函数，或者说 main.c 不知道 hello.c 的存在，那么在 hello-world/CMakeLists.txt 中应该写入：

target_include_directories(helloworld PRIVATE hello)