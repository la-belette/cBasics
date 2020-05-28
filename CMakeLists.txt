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
        string_helper.h memory_manager_tests.c memory_manager_tests.h string_helper_tests.c string_helper_tests.h calendar_helper_tests.c calendar_helper_tests.h matrix_helper_tests.c matrix_helper_tests.h)
