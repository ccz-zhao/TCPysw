cmake_minimum_required(VERSION 3.10)

project(cpp_tcp)

include(cmake/build_type.cmake)
include(cmake/cflags.cmake)

add_subdirectory(test)
add_subdirectory(src)