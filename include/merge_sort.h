//
// Created by majam on 25.04.2025.
//

#ifndef MERGE_SORT_H
#define MERGE_SORT_H
#include <cmath>

template<typename T>
void merge(T* tab, int start, int end, int q) {
    const int n1 = q - start + 1;
    const int n2 = end -q;
    T* first= new T[n1];
    T* second= new T[n2];
    // range [first,last)
    std::copy(tab+start, tab+q+1, first);
    std::copy(tab+q+1,tab+end+1, second);

    int fIndex =0;
    int sIndex = 0;
    int mergedIndex = start;

    while (fIndex < n1 && sIndex < n2) {
        if (first[fIndex]<second[sIndex]) {
            tab[mergedIndex]=first[fIndex];
            fIndex++;
        } else {
            tab[mergedIndex]=second[sIndex];
            sIndex++;
        }
        mergedIndex++;
    }

    while (fIndex<n1) {
        tab[mergedIndex]=first[fIndex];
        fIndex++;
        mergedIndex++;
    }
    while (sIndex<n2) {
        tab[mergedIndex]=second[sIndex];
        sIndex++;
        mergedIndex++;
    }

    delete[] first;
    delete[] second;
}

template<typename T>
void mergesort(T* tab, int start, int end) {
    if (start<end) {
        int q=(start + end)/2;
        mergesort(tab, start, q);
        mergesort(tab, q+1, end);
        merge(tab,start,end,q);
    }
}
#endif //MERGE_SORT_H
