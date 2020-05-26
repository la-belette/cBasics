cmake_minimum_required(VERSION 3.14)
project(cBasics)

set(CMAKE_C_STANDARD 99)

add_executable(cBasics matrix_helper.c main.c matrix_helper.h string_helper.h string_helper.c common.h memory_manager.c memory_manager.h calendar_helper.c calendar_helper.h)