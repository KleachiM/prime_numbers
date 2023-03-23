cmake_minimum_required(VERSION 3.24)
project(prime_numbers)

set(CMAKE_CXX_STANDARD 17)

add_executable(prime_numbers main.cpp Functions.cpp Functions.h)
add_subdirectory(tests)