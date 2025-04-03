//
// Created by skwasnik on 03.04.2025.
//

#ifndef HEAPSORT_H
#define HEAPSORT_H


template<typename T>
class HeapSort {
public:
    static void heapSort(T arr[], size_t n);
private:
    static void heapify(T arr[], int n, int i);
    static void swap(T& a, T& b);
};



#endif //HEAPSORT_H
