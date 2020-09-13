cmake_minimum_required(VERSION 3.14)
project(second_day)

set(CMAKE_CXX_STANDARD 14)

add_executable(base main.cpp)

add_executable( class class.cpp Circle.cpp)