#ifndef QUICK_SORT_H
#define QUICK_SORT_H
template<typename T>
int partition(T *tab,int start, int end, T pivot) {
    int i = start-1;
    int j = end + 1;
    while (true) {
        do {
            j--;
        }while (tab[j]>pivot);
        do {
            i++;
        }while (tab[i]<pivot);
        if (i<j) {
            T swap = tab[i];
            tab[i]=tab[j];
            tab[j] = swap;
        }else {
            return j;
        }
    }
}

template<typename T>
void quicksort(T *tab,int start, int end) {
    if (start<end) {

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(start, end);
        int pivotIndex = dist(gen);
        T pivotValue = tab[pivotIndex];

        int q= partition(tab, start, end, pivotValue);
        quicksort(tab, start, q);
        quicksort(tab, q+1, end);
    }
}
#endif //QUICK_SORT_H
