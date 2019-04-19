cmake_minimum_required(VERSION 3.12)
project(gravityModelling)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

add_executable(gravityModelling main.cpp
    ../src/Shape2D.cpp ../include/Shape2D.h
    ../src/Sphere.cpp ../include/Sphere.h
    ../src/LinSpace1D.cpp ../include/LinSpace1D.h
    ../include/Model.hpp
    ../include/ObservedAnomaly1D.h ../src/ObservedAnomaly1D.cpp)

