//
// Created by majam on 25.04.2025.
//

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

template<typename T>
void merge(T* array, int start, int end, int q) {
    const int n1 = q - start + 1;
    const int n2 = end -q;
    T* first= new T[n1];
    T* second= new T[n2];
    std::copy(array+start, array+q+1, first);
    std::copy(array+q+1,array+end+1, second);

    int fIndex =0;
    int sIndex = 0;
    int mergedIndex = start;

    while (fIndex < n1 && sIndex < n2) {
        if (first[fIndex]<second[sIndex]) {
            array[mergedIndex]=first[fIndex];
            fIndex++;
        } else {
            array[mergedIndex]=second[sIndex];
            sIndex++;
        }
        mergedIndex++;
    }

    while (fIndex<n1) {
        array[mergedIndex]=first[fIndex];
        fIndex++;
        mergedIndex++;
    }
    while (sIndex<n2) {
        array[mergedIndex]=second[sIndex];
        sIndex++;
        mergedIndex++;
    }

    delete[] first;
    delete[] second;
}

template<typename T>
void mergesort(T* array, int start, int end) {
    if (start<end) {
        int q=(start + end)/2;
        mergesort(array, start, q);
        mergesort(array, q+1, end);
        merge(array,start,end,q);
    }
}
#endif //MERGE_SORT_H
