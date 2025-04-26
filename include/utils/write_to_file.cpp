//
// Created by majam on 25.04.2025.
//
#include "write_to_file.h"

#include <fstream>
#include <iostream>

void toFile(int algorythmChoice, const unsigned long long duration, const int size, const float presort) {
    std::string fileName;
    std::string algorythmName;
    switch (algorythmChoice) {
        case 1: {
            fileName = "quick_sort.txt";
            algorythmName = "Quicksort";
            break;
        }
        case 2: {
            fileName = "merge_sort.txt";
            algorythmName = "Quicksort";
            break;
        }
        case 3: {
            fileName = "intro_sort.txt";
            algorythmName = "Quicksort";
            break;
        }
        default: {
            std::cerr << "Unknown operation" << std::endl;
            break;
        }
    }


    std::ofstream file(fileName, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    file<< "\nArray size: "<< size;
    file<< "\nArray presort: "<< presort*100 << "%";
    file << "\n" << algorythmName << " results measured in microseconds: " << duration << "\n";
}