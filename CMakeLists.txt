cmake_minimum_required(VERSION 3.30)
project(AlgorithmsPart1)

set(CMAKE_CXX_STANDARD 20)

add_executable(AlgorithmsPart1 main.cpp
        include/arrays_generator.h
        include/arrays_generator.cpp
        include/quick-sort.cpp
        include/merge-sort.cpp
        include/introsort.cpp
        include/quick-sort.h)
