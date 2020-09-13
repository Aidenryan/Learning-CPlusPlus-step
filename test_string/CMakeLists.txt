# cmake_minimum_required(VERSION <specify CMake version here>)
project(test_string)

set(CMAKE_CXX_STANDARD 14)

add_executable(test_string main.cpp )

add_executable(odd_string  odd_string.c )

add_executable(const_pra  const_pra.c)

add_executable(double_point  double_point.c)

add_executable(point_array  point_array.c)

add_executable(2D_array  2D_array.c)

add_executable(dynamic_array  dynamic_array.c)

add_executable(hw_1  hw_1.c)

add_executable(hw_2  hw_2.c)