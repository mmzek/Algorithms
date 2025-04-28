#ifndef QUICK_SORT_H
#define QUICK_SORT_H

template<typename T>
int median(T* array, int a, int b, int c) {
    if ((array[a] <= array[b] && array[b] <= array[c]) || (array[c] <= array[b] && array[b] <= array[a]))
        return b;
    if ((array[b] <= array[a] && array[a] <= array[c]) || (array[c] <= array[a] && array[a] <= array[b]))
        return a;
    return c;
}

template<typename T>
int partition(T *array,int start, int end) {
    int pivotIndex = median(array, start, (start + end) / 2, end);
    T pivot = array[pivotIndex];
    array[pivotIndex] = array[start];
    array[start] = pivot;

    int i = start-1;
    int j = end + 1;
    while (true) {
        do {
            j--;
        }while (array[j]>pivot);
        do {
            i++;
        }while (array[i]<pivot);
        if (i<j) {
            T swap = array[i];
            array[i]=array[j];
            array[j] = swap;
        }else {
            return j;
        }
    }
}

template<typename T>
void quicksort(T *array,int start, int end) {
    if (start<end) {
        int q= partition(array, start, end);
        quicksort(array, start, q);
        quicksort(array, q+1, end);
    }
}
#endif //QUICK_SORT_H
