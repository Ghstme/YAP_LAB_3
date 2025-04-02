cmake_minimum_required(VERSION 3.28)
project(Lab_3_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab_3_2 main.cpp
        FlyingBird.cpp
        Bird.cpp
        Fish.cpp
        FlyingBird.h
        Bird.h
        Fish.h
        Animal.h)
