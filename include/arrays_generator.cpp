//
// Created by majam on 04.04.2025.
//
#include "arrays_generator.h"

#include <iostream>
#include <random>

void generateArrays() {
    const int sizes[] = {100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000};
    //testing only one array of each size for now
    for (int size : sizes) {
        int* array = new int[size];

        randomNumbersGenerator(array, size);
        std::cout << "Array size: " << size << ":\n";
        for (int i = 0; i < size; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << "\n\n";

        delete[] array;
    }
}

void randomNumbersGenerator(int* array, int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(INT32_MIN, INT32_MAX);

    for (int i = 0; i < size; ++i) {
        array[i] = dist(gen);
    }
}