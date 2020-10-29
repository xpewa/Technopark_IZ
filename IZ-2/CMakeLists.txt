cmake_minimum_required(VERSION 3.16)
project(IZ_2 C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-Wall -Werror")

add_subdirectory(lib_static)
add_subdirectory(lib_shared)

add_executable(IZ2_static main_static.c)
target_link_libraries(IZ2_static PUBLIC static_lib)

add_executable(IZ2_shared main_shared.c)
target_link_libraries(IZ2_shared PRIVATE shared_lib ${CMAKE_DL_LIBS})