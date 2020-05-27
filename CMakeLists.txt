cmake_minimum_required(VERSION 3.14)
project(cBasics C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(cBasics
        calendar_helper.c
        calendar_helper.h
        common.h
        main.c
        matrix_helper.c
        matrix_helper.h
        memory_manager.c
        memory_manager.h
        string_helper.c
        string_helper.h)
