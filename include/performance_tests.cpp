//
// Created by majam on 04.04.2025.
//
#include "performance_tests.h"

#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

#include "utils/write_to_file.h"
#include "intro_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"

const int sizes[] = {100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000};
constexpr float presorts[] = {0, 0.25, 0.5, 0.75, 0.95, 0.99, 0.997, 1};

void pre_sort(int *array, const int size, const float presort) {
    std::sort(array, array + static_cast<int>(static_cast<float>(size) * presort));

    if (presort == 1.0) {
        std::reverse(array, array + size);
    }
}

void performance_tests(int algorithmChoice, int size, float presort) {
    long long currentDuration = 0;

    for (int i = 0; i < 100; i++) {
        int *array = new int[size];

        randomNumbersGenerator(array, size);
        pre_sort(array, size, presort);

        switch (algorithmChoice) {
            case 1: {
                auto start = std::chrono::high_resolution_clock::now();
                quicksort<int>(array, 0, size - 1);
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = duration_cast<std::chrono::nanoseconds>(stop - start);
                currentDuration += duration.count();
                break;
            }
            case 2: {
                auto start = std::chrono::high_resolution_clock::now();
                mergesort<int>(array, 0, size - 1);
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = duration_cast<std::chrono::nanoseconds>(stop - start);
                currentDuration += duration.count();
                break;
            }
            case 3: {
                auto start = std::chrono::high_resolution_clock::now();
                //introsort<int>(array, 0, size - 1);
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = duration_cast<std::chrono::nanoseconds>(stop - start);
                currentDuration += duration.count();

                break;
            }
            default:
                std::cout << "Wrong choice\n";
                break;
        }

        delete[] array;
    }
    toFile(algorithmChoice, currentDuration / 100, size, presort);

    std::string algorithmName;
    if (algorithmChoice ==1) {
        algorithmName = "quicksort";
    }else if (algorithmChoice ==2){
        algorithmName = "mergesort";
    }else if (algorithmChoice ==3) {
        algorithmName = "introsort";
    }
    std::cout << "\nTime duration of " <<algorithmName<< " for " << size << " array size with " << presort <<
            " presorted values was written to file." << "\n";
}


int chooseAlgorythm() {
    while (true) {
        int algorithmChoice = 0;
        std::cout << "\nChoose the algorithm:\n1-Quick sort\n2-Merge sort\n3-Intro sort\n4-All tests at once\n0-Exit\n";
        std::cin >> algorithmChoice;

        if (algorithmChoice == 0) return 0;
        if (algorithmChoice != 4) {
            int sizeChoice = 0;
            int presortChoice = 0;
            std::cout <<
                    "\nChoose size:\n1-100\n2-500\n3-1000\n4-5000\n5-10000\n6-50000\n7-100000\n8-500000\n9-1000000\n";
            std::cin >> sizeChoice;
            std::cout << "\nChoose presort:\n1-0%\n2-25%\n3-50%\n4-75%\n5-95%\n6-99%\n7-99.7%\n8-100%\n";
            std::cin >> presortChoice;

            const int size = sizes[sizeChoice - 1];
            const float presort = presorts[presortChoice - 1];
            performance_tests(algorithmChoice, size, presort);

        }else {
            for (int algorythm =1; algorythm<=3; algorythm ++) {
                for (int size=0;size<9;size++) {
                    for (int presort=0; presort<8; presort++) {
                        performance_tests(algorythm, sizes[size], presorts[presort]);
                    }
                }
            }
        }
    }
}


void randomNumbersGenerator(int *array, int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(INT32_MIN, INT32_MAX);
    for (int i = 0; i < size; ++i) {
        array[i] = dist(gen);
    }
}

