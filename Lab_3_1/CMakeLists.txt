cmake_minimum_required(VERSION 3.28)
project(Lab_3_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab_3_1 main.cpp
        CylinderVolume.cpp
        CylinderVolume.h
        Square.cpp
        Square.h
        Triangle.cpp
        Triangle.h
        Rectangle.cpp
        Rectangle.h
        Circle.cpp
        Circle.h
        Figure.h
)
