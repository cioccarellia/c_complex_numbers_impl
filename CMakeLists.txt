cmake_minimum_required(VERSION 3.17)
project(complessi C)

set(CMAKE_C_STANDARD 99)

add_executable(complessi main.c model/complexn.c model/complexn.h)