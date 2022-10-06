
add_library(helloworld SHARED hello-world.c)

add_subdirectory(hello)

target_link_libraries(helloworld PRIVATE hello)
target_include_directories(helloworld PRIVATE hello)