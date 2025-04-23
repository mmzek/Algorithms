template<typename T>
int partition(T *tab,int start, int end) {
    T pivot = tab[start];
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
            int swap = tab[i];
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
        int q= partition(tab, start, end);
        quicksort(tab, start, q);
        quicksort(tab, q+1, end);
    }
}