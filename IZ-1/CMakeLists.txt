cmake_minimum_required(VERSION 3.9)
project(IZ-1 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

enable_testing()
add_subdirectory(Google_tests)

add_library(IZ-1 STATIC main.c functions.h)

add_executable(IZ_1 main.c functions.h)


