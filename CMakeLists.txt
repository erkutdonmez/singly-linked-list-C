cmake_minimum_required(VERSION 4.1)
project(singly_linked_list_C C)

set(CMAKE_C_STANDARD 11)

add_executable(singly_linked_list_C main.c
        linked_list.c
        linked_list.h)
