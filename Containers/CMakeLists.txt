cmake_minimum_required(VERSION 3.14)
project(Containers)

set(CMAKE_CXX_STANDARD 14)

add_executable(Containers main.cpp)

add_executable(Vector Vector.cpp)

add_executable(Deque Deque.cpp)

add_executable(Stack Stack.cpp)

add_executable(Function_obj Function_obj.cpp)