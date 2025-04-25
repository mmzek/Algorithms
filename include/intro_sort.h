//
// Created by majam on 25.04.2025.
//

#ifndef INTRO_SORT_H
#define INTRO_SORT_H
#include <bits/stdc++.h>
#include "quick_sort.h"

template<typename T>
void heapify(T* tab, int index, int size) {
    int largest=index;
    int left = 2*index+1;
    int right = 2*index+2;
    if (left<size && tab[left]>tab[largest]) {
        largest = left;
    }
    if (right<size && tab[right]>tab[largest]) {
        largest = right;
    }
    if (largest != index) {
        T swap = tab[largest];
        tab[largest] = tab[index];
        tab[index] = swap;
        heapify(tab, largest, size);
    }
}

template<typename T>
void buildHeap(T* tab, int size) {
    for (int i=size/2 -1; i>=0; i--) {
        heapify(tab, i, size);
    }
}
template<typename T>
void heapsort(T* tab, int size) {
    buildHeap(tab,size);
    for (int i= size-1; i>0; i--) {
        T swap=tab[0];
        tab[0]=tab[i];
        tab[i]=swap;
        heapify(tab, 0, i);
    }
}

template<typename T>
void insertion_sort(T* tab, int size) {
    for (int i=0; i<size;i++) {
        T key = tab[i];
        int insert = i - 1;
        while (insert>=0 && tab[insert] > key) {
            tab [insert+1] = tab [insert];
            insert= insert-1;
        }
        tab[insert+1] = key;
    }
}

template<typename T>
int median(T* tab, int a, int b, int c) {
        if ((tab[a] <= tab[b] && tab[b] <= tab[c]) || (tab[c] <= tab[b] && tab[b] <= tab[a]))
            return b;
        if ((tab[b] <= tab[a] && tab[a] <= tab[c]) || (tab[c] <= tab[a] && tab[a] < tab[b]))
            return a;
        return c;
}

template<typename T>
void intro_sort(T* tab, int start, int end, const int limit) {
    const int size = end-start+1;

    if (limit <= 0) {
        heapsort(tab+start, size);
        return;
    }

    int pivot = median(tab, start, start+size/2, end);
    int swap = tab[start];
    tab[start]=tab[pivot];
    tab[pivot]=swap;

    int part = partition(tab, start, end, tab[start]);

    if (part>9)
        intro_sort(tab, start, part - 1, limit - 1);
    if (end - part >9)
    intro_sort(tab, part + 1, end, limit - 1);
}

template<typename T>
void introspective_sort(T* tab, int start, int end) {
    int size = end-start+1;
    int limit = static_cast<int>(floor(2 * std::log(size)));

    intro_sort(tab, start, end, limit);
    insertion_sort(tab + start, size);
}
#endif //INTRO_SORT_H
