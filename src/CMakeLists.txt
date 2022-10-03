SET(EXECUTABLE_OUTPUT_DIRECTORY ${PRPJECT_BINARY_DIR}/bin)

# 查找当前目录下所有源文件，并将文件名保存到DIR_SOURCE
AUX_SOURCE_DIRECTORY(. DIR_SOURCE)
# add the executable
ADD_EXECUTABLE(${PROJECT_NAME} ${DIR_SOURCE})

#添加动态连接库的路径
link_directories(${PROJECT_SOURCE_DIR}/lib) 
#添加libmxnet.so
# target_link_libraries(${APP_NAME} -lmxnet ) 
target_link_libraries(${PROJECT_NAME} -lm ) 

# 添加静态库libm.a
# add_library(m STATIC IMPORTED)
# set_property(TARGET m PROPERTY IMPORTED_LOCATION /usr/i686-w64-mingw32/lib/libm.a)
# target_link_libraries(${APP_NAME} m )