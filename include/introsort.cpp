//
// Created by majam on 24.04.2025.
//

#include <bits/stdc++.h>
#include "quick-sort.h"


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
void insertionSort(T* tab, int size) {
    for (int i=0; i<size-1;i++) {
        int key = tab[i];
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
        if ((tab[a] < tab[b] && tab[b] < tab[c]) || (tab[c] <= tab[b] && tab[b] <= tab[a]))
            return b;

        if ((tab[a] < tab[c] && tab[c] <= tab[b]) || (tab[b] < tab[c] && tab[c] <= tab[a]))
            return c;

        if ((tab[b] <= tab[a] && tab[a] < tab[c]) || (tab[c] <= tab[a] && tab[a] < tab[b]))
            return a;
}

template<typename T>
void introSortUtil(T* tab, int start, int end, int depthLimit) {
    int size = end - start;

    if (size <20) {
        insersionSort(tab, start, end);
    }
    if (depthLimit == 0) {
        heapsort(tab, size);
    }

    int pivot = median(tab, start, start+size/2, end);

    const int swap = pivot;
    pivot = end;
    end = swap;

    int partition = partition(tab, start, end);
    introSortUtil(tab, start, partition -1, depthLimit -1);
    introSortUtil(tab, partition + 1, end, depthLimit -1);
}

template<typename T>
void introSort(T* tab, int start, int end) {
    int depthLimit = 2 * std::log(end-start);
    introSortUtil(tab,start, end, depthLimit);
}