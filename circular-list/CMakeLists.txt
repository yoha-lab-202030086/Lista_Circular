cmake_minimum_required(VERSION 4.1)
project(circular_list)

set(CMAKE_CXX_STANDARD 20)

add_executable(circular_list main.cpp
        Node.h
        Node.cpp
        CList.h
        CList.cpp)
