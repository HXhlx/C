cmake_minimum_required(VERSION 3.14)
project(C C)

set(CMAKE_C_STANDARD 11)

add_executable(C set.h set.c useset.c)