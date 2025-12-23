cmake_minimum_required(VERSION 3.30)
project(projetlo21 C)

set(CMAKE_C_STANDARD 90)

add_executable(projetlo21 main.c
        cmake-build-debug/BaseFait.c
        cmake-build-debug/BaseFait.h)
