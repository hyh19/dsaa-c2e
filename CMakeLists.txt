cmake_minimum_required(VERSION 3.23)
project(dsaa-c2e C)

set(CMAKE_C_STANDARD 99)

add_executable(testlist testlist.c list.c list.h fatal.h)
add_executable(teststka teststka.c stackar.c stackar.h)
add_executable(teststkl teststkl.c stackli.c stackli.h)
add_executable(testque testque.c queue.c queue.h)

add_executable(testtree testtree.c tree.c tree.h)
