#include "QuickSort.h"

template <typename T>
typename QuickSort<T>::PivotType QuickSort<T>::currentPivotType;

template <typename T>
void QuickSort<T>::sort(T arr[], size_t arr_size, PivotType pivot) {

    if (arr_size <= 1) return;
    QuickSort::currentPivotType = pivot;
    insideQuickSort(arr, 0, arr_size - 1);
}

template <typename T>
void QuickSort<T>::swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
int QuickSort<T>::partition(T* array, int left, int right) {

    T pivot;
    switch (currentPivotType) {
        case LEFT:
            pivot = array[left];
            break;
        case RIGHT:
            pivot = array[right];
            break;
        case RANDOM: {
            int randomIndex = left + rand() % (right - left);
            swap(array[randomIndex], array[right]);
            pivot = array[right];
            break;
        }
        case MIDDLE: {
            int middleIndex = left + (right - left) / 2;
            swap(array[middleIndex], array[right]);
            pivot = array[right];
            break;
        }
    }
    

    if (currentPivotType == LEFT) {
        int i = (left + 1);
        int j = right;

        while (true) {
            while (i <= j && array[i] <= pivot) {
                i++;
            }

            while (i <= j && array[j] >= pivot) {
                j--;
            }

            if (i < j) {
                swap(array[i], array[j]);
            } else {
                // Swap pivot with the right pointer
                swap(array[left], array[j]);
                return j;
            }
        }
    }

    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }

    swap(array[i + 1], array[right]);
    return (i + 1);
}

template <typename T>
void QuickSort<T>::insideQuickSort(T* array, int left, int right) {
    if (left < right) {
        int pi = partition(array, left, right);
        insideQuickSort(array, left, pi - 1);
        insideQuickSort(array, pi + 1, right);
    }
}