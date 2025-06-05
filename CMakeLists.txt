cmake_minimum_required(VERSION 3.31)
project(str_has_prefix C)

set(CMAKE_C_STANDARD 11)

add_library(str_has_prefix STATIC library.c)
