cmake_minimum_required(VERSION 3.28)
project(Lab_3_3)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab_3_3 main.cpp
        FileIO.cpp
        FileIO.h
        Teacher.cpp
        Teacher.h
        Student.cpp
        Student.h
        Human.cpp
        Human.h)
