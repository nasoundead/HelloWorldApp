CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
# set the project name
PROJECT(HelloWorldApp)

enable_testing()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/archive)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/library)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/runtime)
# set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/path)

ADD_SUBDIRECTORY(3rd/str)
ADD_SUBDIRECTORY(src)

