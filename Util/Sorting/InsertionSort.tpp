
#include "InsertionSort.h"


template <typename T>
void InsertionSort<T>::insertionSort(T array[], size_t size)
{
      for (int step = 1; step < size; step++) {
        T key = array[step];
        int j = step - 1;

        while (j >=0 && key < array[j]) {
          array[j + 1] = array[j];
          --j;
        }
        array[j + 1] = key;
      }
}
