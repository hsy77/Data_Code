cmake_minimum_required(VERSION 3.15)
project(Ordered_list)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ordered_list main.cpp Ordered_list.cpp Ordered_list.h binary_search.cpp binary_search.h List.h List.cpp)