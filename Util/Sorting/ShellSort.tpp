
#include "ShellSort.h"


template <typename T>
void ShellSort<T>::sort(T arr[], size_t n, shellType type) {
    switch (type) {
        case KNUTH:
            knuthSort(arr, n);
        break;
        case HIBBARD:
            hibbardSort(arr, n);
        break;
        default:
            throw std::invalid_argument("Invalid shell sort type");
    }
}

template<typename T>
void ShellSort<T>::knuthSort(T array[], size_t n) {
    // Użycie wzoru Knutha: h = 3*h + 1
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;
    }

    while (h >= 1) {
        for (int i = h; i < n; i++) {
            T temp = array[i];
            int j;
            for (j = i; j >= h && array[j - h] > temp; j -= h) {
                array[j] = array[j - h];
            }
            array[j] = temp;
        }
        h /= 3;
    }
}

template<typename T>
void ShellSort<T>::hibbardSort(T array[], size_t n) {
    // Użycie wzoru Hibbarda: h = 2^k - 1
    AizoArray<int> gaps;
    for (int k = 1; (1 << k) - 1 < n; k++) {
        gaps.push_back((1 << k) - 1);
    }

    for (int g = gaps.size() - 1; g >= 0; g--) {
        int h = gaps[g];
        for (int i = h; i < n; i++) {
            T temp = array[i];
            int j;
            for (j = i; j >= h && array[j - h] > temp; j -= h) {
                array[j] = array[j - h];
            }
            array[j] = temp;
        }
    }
}