cmake_minimum_required(VERSION 3.15)
project(tree_test)

set(CMAKE_CXX_STANDARD 14)

add_executable(tree_test main.cpp Build_tree.cpp Build_tree.h split.h split.cpp)