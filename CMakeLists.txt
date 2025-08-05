cmake_minimum_required(VERSION 3.27)
project(calculator C)

set(CMAKE_C_STANDARD 11)

include_directories(inc)

add_executable(calculator src/main.c
        src/expression_handler.c)
