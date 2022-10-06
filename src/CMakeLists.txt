SET(EXECUTABLE_OUTPUT_DIRECTORY ${PRPJECT_BINARY_DIR}/bin)

# 查找当前目录下所有源文件，并将文件名保存到DIR_SOURCE
AUX_SOURCE_DIRECTORY(. DIR_SOURCE)
# add the executable
ADD_EXECUTABLE(${PROJECT_NAME} ${DIR_SOURCE})

add_subdirectory(hello-world)

#添加动态连接库的路径
link_directories(${CMAKE_SOURCE_DIR}/library) 

target_include_directories(${PROJECT_NAME} PRIVATE hello-world)
target_link_libraries(${PROJECT_NAME} helloworld ) 

target_link_libraries(${PROJECT_NAME} -lm ) 

