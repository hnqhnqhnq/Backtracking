cmake_minimum_required(VERSION 3.25)
project(Backtracking C)

set(CMAKE_C_STANDARD 23)

add_executable(Backtracking main.c permutation.h permutation.c combinations.h combinations.c)
