cmake_minimum_required(VERSION 3.16)
project(IZ_2 C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(lib_static)

add_executable(IZ2_static main_static.c)
target_link_libraries(IZ2_static PUBLIC static_lib)