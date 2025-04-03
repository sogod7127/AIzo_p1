//
// Created by skwasnik on 03.04.2025.
//

#include "../AizoArray.h"

#ifndef QUICKSORT_H
#define QUICKSORT_H

template <typename T>
class QuickSort {
public:
    static void sort(T arr[], size_t arr_size);

private:
    static void swap(T& a, T& b);
    static int partition(T* array, int low, int high);
    static void insideQuickSort(T* array, int low, int high);
};

#endif //QUICKSORT_H
