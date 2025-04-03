//
// Created by skwasnik on 03.04.2025.
//

#include "InsertionSort.h"


template <typename T>
void InsertionSort<T>::insertionSort(T array[], size_t size)
{
      for (int step = 1; step < size; step++) {
        T key = array[step];
        int j = step - 1;

        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<array[j] to key>array[j].
        while (j >=0 && key < array[j]) {
          array[j + 1] = array[j];
          --j;
        }
        array[j + 1] = key;
      }
}
