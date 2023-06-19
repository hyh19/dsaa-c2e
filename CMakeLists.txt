cmake_minimum_required(VERSION 3.23)
project(dsaa-c2e C)

set(CMAKE_C_STANDARD 99)

add_executable(list testlist.c list.c list.h fatal.h)
