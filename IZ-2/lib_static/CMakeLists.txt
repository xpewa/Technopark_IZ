cmake_minimum_required(VERSION 3.16)
project(lib_static C)

set(CMAKE_C_STANDARD 11)

set(SOURCES llibrary_static.c ../src/letter.c ../src/search.c)
set(HEADERS llibrary_static.h ../include/letter.h ../include/search.h)
add_library(static_lib STATIC ${SOURCES} ${HEADERS})
target_include_directories(static_lib PUBLIC .)