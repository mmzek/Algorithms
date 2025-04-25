cmake_minimum_required(VERSION 3.30)
project(AlgorithmsPart1)

set(CMAKE_CXX_STANDARD 20)

add_executable(AlgorithmsPart1 main.cpp
        include/performance_tests.h
        include/performance_tests.cpp
        include/quick_sort.h
        include/merge_sort.h
        include/intro_sort.h
        include/utils/write_to_file.cpp
        include/utils/write_to_file.h)
