cmake_minimum_required(VERSION 3.29)
project(Matam_HW_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(dry)
include_directories(wet)

add_executable(Matam_HW_2
    dry/main.cpp
    dry/Pirate.cpp
    dry/Pirate.h
    wet/Matrix.cpp
    wet/Matrix.h
    wet/tests.cpp
    wet/Utilities.cpp
    wet/Utilities.h)
