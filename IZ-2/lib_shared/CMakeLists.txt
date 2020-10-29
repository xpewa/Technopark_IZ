cmake_minimum_required(VERSION 3.16)
project(lib_shared C)

set(CMAKE_C_STANDARD 11)

set(SOURCES library_shared.c ../src/letter.c ../src/search.c)
set(HEADERS library_shared.h ../include/letter.h ../include/search.h)

add_library(shared_lib SHARED ${SOURCES} ${HEADERS})
target_include_directories(shared_lib PRIVATE .)
target_link_libraries(shared_lib pthread)