//
// Created by skwasnik on 03.04.2025.
//

#include "HeapSort.h"


template<typename T>
void HeapSort<T>::heapify(T arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}


template<typename T>
void HeapSort<T>::heapSort(T arr[], size_t n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);

        // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
    }
}

template<typename T>
void HeapSort<T>::swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}