cmake_minimum_required(VERSION 3.31)
project(lo21 C)

set(CMAKE_C_STANDARD 90)

add_executable(lo21 main.c
                BaseFait.c
                BaseConnaisance.c
                regle.c
                interface2.c
                interface.h
                BaseFait.h
        TEST.c
        TEST.h)
