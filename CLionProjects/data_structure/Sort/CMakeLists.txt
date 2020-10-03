cmake_minimum_required(VERSION 3.15)
project(Sort)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sort main.cpp Radix_Sorting.cpp Radix_Sorting.h Record.cpp Record.h QuickSort.cpp QuickSort.h MergingSort.cpp MergingSort.h)