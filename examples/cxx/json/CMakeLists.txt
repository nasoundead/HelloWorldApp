set(CMAKE_CXX_FLAGS, "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")

# message(WARNING "CMAKE_SOURCE_DIR:${CMAKE_SOURCE_DIR}")
add_subdirectory( ${CMAKE_SOURCE_DIR}/3rd/json ${CMAKE_SOURCE_DIR}/library)

set(target_name json_demo)

add_executable(${target_name} main.cpp)

target_link_libraries( ${target_name} PRIVATE nlohmann_json )

target_include_directories(
    ${target_name}
    INTERFACE
    ${NLOHMANNJSON_ROOT}/include
)