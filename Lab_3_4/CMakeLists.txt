cmake_minimum_required(VERSION 3.28)
project(Lab_3_4)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab_3_4 main.cpp
        CubeSummator.cpp
        CubeSummator.h
        SquareSummator.cpp
        SquareSummator.h
        Summator.cpp
        Summator.h)
