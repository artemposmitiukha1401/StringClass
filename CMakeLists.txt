cmake_minimum_required(VERSION 3.31)
project(string_class)

set(CMAKE_CXX_STANDARD 20)

add_executable(string_class main.cpp
        MyString.cpp
        MyString.h
)
