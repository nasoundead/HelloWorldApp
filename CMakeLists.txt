CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
# set the project name
PROJECT(HelloWorldApp)

enable_testing()

# CMAKE_BINARY_DIR: The path to the top level of the build tree.  
# This is the directory in which you ran the cmake command.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/archive)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/library)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/runtime)

# PROJECT_BINARY_DIR: Top level binary directory for the current project.  
# Not every CMakeLists.txt file defines a project
# –this is the directory in the build tree that corresponds to the most recent CMakeLists.txt file that defined a project.
message(STATUS "PROJECT_BINARY_DIR:${PROJECT_BINARY_DIR}")

ADD_SUBDIRECTORY(3rd/str)
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(examples)

