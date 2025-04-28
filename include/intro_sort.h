#ifndef INTRO_SORT_H
#define INTRO_SORT_H
#include <bits/stdc++.h>
#include "quick_sort.h"

template<typename T>
void heapify(T* array, int index, int size) {
    int largest=index;
    int left = 2*index+1;
    int right = 2*index+2;
    if (left<size && array[left]>array[largest]) {
        largest = left;
    }
    if (right<size && array[right]>array[largest]) {
        largest = right;
    }
    if (largest != index) {
        T swap = array[largest];
        array[largest] = array[index];
        array[index] = swap;
        heapify(array, largest, size);
    }
}

template<typename T>
void buildHeap(T* array, int size) {
    for (int i=size/2 -1; i>=0; i--) {
        heapify(array, i, size);
    }
}
template<typename T>
void heapsort(T* array, int size) {
    buildHeap(array,size);
    for (int i= size-1; i>0; i--) {
        T swap=array[0];
        array[0]=array[i];
        array[i]=swap;
        heapify(array, 0, i);
    }
}

template<typename T>
void insertion_sort(T* array, int size) {
    for (int i=0; i<size;i++) {
        T key = array[i];
        int insert = i - 1;
        while (insert>=0 && array[insert] > key) {
            array [insert+1] = array [insert];
            insert= insert-1;
        }
        array[insert+1] = key;
    }
}

template<typename T>
void intro_sort(T* array, int start, int end, const int limit) {
    if (end>start) {
        const int size = end-start+1;

        if (limit <= 0) {
            heapsort(array+start, size);
            return;
        }
        int part = partition(array, start, end);

        if (part>9)
            intro_sort(array, start, part, limit - 1);
        if (end - part >9)
            intro_sort(array, part + 1, end, limit - 1);
    }
}

template<typename T>
void introspective_sort(T* array, int start, int end) {
    int size = end-start+1;
    int limit = static_cast<int>(std::floor(2 * std::log(size)));

    intro_sort(array, start, end, limit);
    insertion_sort(array + start, size);
}
#endif //INTRO_SORT_H
