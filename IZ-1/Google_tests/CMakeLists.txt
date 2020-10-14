cmake_minimum_required(VERSION 3.16)
project(Tests LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

add_executable(Tests TestInsertionSort.cpp)
target_link_libraries(Tests PUBLIC
    gtest_main IZ-1
)

add_test(
        NAME Tests
        COMMAND Tests
)