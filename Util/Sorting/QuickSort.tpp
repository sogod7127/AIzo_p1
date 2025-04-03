// QuickSort.tpp
#include "QuickSort.h"

template <typename T>
void QuickSort<T>::sort(T arr[], size_t arr_size) {

    if (arr_size <= 1) return;
    insideQuickSort(arr, 0, arr_size - 1);
}

template <typename T>
void QuickSort<T>::swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
int QuickSort<T>::partition(T* array, int low, int high) {
    T pivot = array[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }

    swap(array[i + 1], array[high]);
    return (i + 1);
}

template <typename T>
void QuickSort<T>::insideQuickSort(T* array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        insideQuickSort(array, low, pi - 1);
        insideQuickSort(array, pi + 1, high);
    }
}