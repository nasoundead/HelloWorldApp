# cmake：target_** 中的 PUBLIC，PRIVATE，INTERFACE

## 指令说明
target_include_directories()：指定目标包含的头文件路径。官方文档

target_link_libraries()：指定目标链接的库。官方文档

target_compile_options()：指定目标的编译选项。官方文档

目标 由 add_library() 或 add_executable() 生成。

这三个指令类似，这里以 target_include_directories() 为例进行讲解。

## 指令讲解
测试工程目录结构：

cmake-test/                 工程主目录，main.c 调用 libhello-world.so
├── CMakeLists.txt
├── hello-world             生成 libhello-world.so，调用 libhello.so 和 libworld.so
│   ├── CMakeLists.txt
│   ├── hello               生成 libhello.so 
│   │   ├── CMakeLists.txt
│   │   ├── hello.c
│   │   └── hello.h         libhello.so 对外的头文件
│   ├── hello_world.c
│   ├── hello_world.h       libhello-world.so 对外的头文件
│   └── world               生成 libworld.so
│       ├── CMakeLists.txt
│       ├── world.c
│       └── world.h         libworld.so 对外的头文件
└── main.c
调用关系：

                                 ├────libhello.so
可执行文件────libhello-world.so
                                 ├────libworld.so
关键字用法说明：

PRIVATE：私有的。生成 libhello-world.so时，只在 hello_world.c 中包含了 hello.h，libhello-world.so 对外的头文件——hello_world.h 中不包含 hello.h。而且 main.c 不会调用 hello.c 中的函数，或者说 main.c 不知道 hello.c 的存在，那么在 hello-world/CMakeLists.txt 中应该写入：

target_link_libraries(hello-world PRIVATE hello)
target_include_directories(hello-world PRIVATE hello)
INTERFACE：接口。生成 libhello-world.so 时，只在libhello-world.so 对外的头文件——hello_world.h 中包含 了 hello.h， hello_world.c 中不包含 hello.h，即 libhello-world.so 不使用 libhello.so 提供的功能，只使用 hello.h 中的某些信息，比如结构体。但是 main.c 需要使用 libhello.so 中的功能。那么在 hello-world/CMakeLists.txt 中应该写入：

target_link_libraries(hello-world INTERFACE hello)
target_include_directories(hello-world INTERFACE hello)
PUBLIC：公开的。PUBLIC = PRIVATE + INTERFACE。生成 libhello-world.so 时，在 hello_world.c 和 hello_world.h 中都包含了 hello.h。并且 main.c 中也需要使用 libhello.so 提供的功能。那么在 hello-world/CMakeLists.txt 中应该写入：

target_link_libraries(hello-world PUBLIC hello)
target_include_directories(hello-world PUBLIC hello)
实际上，这三个关键字指定的是目标文件依赖项的使用范围（scope）或者一种传递（propagate）。官方说明

可执行文件依赖 libhello-world.so， libhello-world.so 依赖 libhello.so 和 libworld.so。

main.c 不使用 libhello.so 的任何功能，因此 libhello-world.so 不需要将其依赖—— libhello.so 传递给 main.c，hello-world/CMakeLists.txt 中使用 PRIVATE 关键字；
main.c 使用 libhello.so 的功能，但是libhello-world.so 不使用，hello-world/CMakeLists.txt 中使用 INTERFACE 关键字；
main.c 和 libhello-world.so 都使用 libhello.so 的功能，hello-world/CMakeLists.txt 中使用 PUBLIC 关键字；
## include_directories(dir)
target_include_directories() 的功能完全可以使用 include_directories() 实现。但是我还是建议使用 target_include_directories()。为什么？保持清晰！

include_directories(header-dir) 是一个全局包含，向下传递。什么意思呢？就是说如果某个目录的 CMakeLists.txt 中使用了该指令，其下所有的子目录默认也包含了header-dir 目录。

上述例子中，如果在顶层的 cmake-test/CMakeLists.txt 中加入：

include_directories(hello-world)
include_directories(hello-world/hello)
include_directories(hello-world/world)
那么整个工程的源文件在编译时都会增加：

-I hello-world -I hello-world/hello -I hello-world/world ...
各级子目录中无需使用 target_include_directories() 或者 include_directories()了。如果此时查看详细的编译过程（make VERBOSE=1）就会发现编译过程是一大坨，很不舒服。

当然了，在最终子目录的 CMakeLists.txt 文件中，使用 include_directories() 和 target_include_directories() 的效果是相同的。

## 目录划分
每一个目录都是一个模块，目录内部应将对外和对内的头文件进行区分，由模块的调用者决定模块是否被传递（PRIVATE，INTERFACE，PUBLIC）。