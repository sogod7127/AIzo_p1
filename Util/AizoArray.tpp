//
// Created by skwasnik on 16.03.2025.
//

#include "AizoArray.h"
#include "../lib.h"
#include "Sorting/HeapSort.tpp"
#include "Sorting/InsertionSort.tpp"
#include "Sorting/QuickSort.tpp"
#include "Sorting/ShellSort.tpp"

template <typename T>
AizoArray<T>::AizoArray(T arr[], size_t arr_size)
{
    reserve(arr_size > 0 ? arr_size : 5);

    for (size_t i = 0; i < arr_size; i++)
    {
        this->push_back(arr[i]);
    }

}

    template <typename T>
    template <size_t N>
    AizoArray<T>::AizoArray(T (&arr)[N]) {

    reserve(N);
    for (int i = 0; i < N; i++) {
        this->push_back(arr[i]);
    }
    }
    template <typename T>
    AizoArray<T>::AizoArray(int dummy) {
        reserve(dummy);
        aizoArraySize = 0;
    }



template <typename T>
AizoArray<T>::AizoArray() {
    reserve(5);
}

template <typename T>
void AizoArray<T>::push_back(T value)
{
    //TODO: Check if there is diffrent type than actually vector is
    if (++aizoArraySize <= reservedSize) {
        aizoArray[aizoArraySize-1] = value;
        primaryAizo[aizoArraySize-1] = value;
    }
    else
    {
        T *temp = new T[aizoArraySize];
        T *primaryTemp = new T[aizoArraySize];
        for (int i = 0; i<reservedSize; i++)
        {
            temp[i] = aizoArray[i];
            primaryTemp[i] = primaryAizo[i];
        }

        temp[aizoArraySize-1] = value;
        primaryTemp[aizoArraySize-1] = value;

        delete [] aizoArray;
        delete [] primaryAizo;
        aizoArray = temp;
        primaryAizo = primaryTemp;
    }
}

template<typename T>
void AizoArray<T>::reserve(size_t size) {
    this->reservedSize = size;
    if (size == 0) {
        this->aizoArray = nullptr;
        this->aizoArraySize = 0;
    } else {
        this->aizoArray = new T[size];
        this->primaryAizo = new T[size];
        this->aizoArraySize = 0; // Start with size 0
    }
}

template<typename T>
void AizoArray<T>::print() {


    for (size_t i = 0; i < aizoArraySize; i++)
        std::cout << aizoArray[i] << (i+1 == int(aizoArraySize) ? "" : ", ");

    std:: cout << std::endl;
}

template<typename T>
void AizoArray<T>::printPrimary() {

    for (size_t i = 0; i < aizoArraySize; i++)
        std::cout << primaryAizo[i] << (i+1 == int(aizoArraySize) ? "" : ", ");

    std:: cout << std::endl;
}

template <typename T>
size_t AizoArray<T>::size() const
{
    return aizoArraySize;
}

template <typename T>
void AizoArray<T>::reshamble() {
    for (size_t i = 0; i < aizoArraySize; i++) {
        aizoArray[i] = primaryAizo[i];
    }
}

template <typename T>
bool AizoArray<T>::isSorted() {
    for (size_t i = 1; i < aizoArraySize; i++) {
        if (aizoArray[i] < aizoArray[i - 1]) {
            return false;
        }
    }
    return true;
}

template <typename T>
T& AizoArray<T>::operator[](size_t index) {
    if (index >= aizoArraySize) {
        throw std::out_of_range("Indeks poza zakresem tablicy");
    }
    return aizoArray[index];
}

template <typename T>
const T& AizoArray<T>::operator[](size_t index) const {
    if (index >= aizoArraySize) {
        throw std::out_of_range("Indeks poza zakresem tablicy");
    }
    return aizoArray[index];
}

template<typename T>
bool AizoArray<T>::empty() {
    return aizoArraySize == 0;
}

template <typename T>
void AizoArray<T>::quickSort(char type) {

    typename QuickSort<T>::PivotType pivotType;
    switch (type) {
        case 'L':
            pivotType = QuickSort<T>::LEFT;
            break;
        case 'R':
            pivotType = QuickSort<T>::RIGHT;
            break;
        case 'M':
            pivotType = QuickSort<T>::MIDDLE;
            break;
        case 'r':
            pivotType = QuickSort<T>::RANDOM;
            break;
        default:
            throw std::invalid_argument("Invalid pivot type");
    }


    QuickSort<T>::sort(this->aizoArray, this->aizoArraySize, pivotType);
}

template <typename T>
void AizoArray<T>::insertionSort() {
    InsertionSort<T>::insertionSort(this->aizoArray, this->aizoArraySize);
}

template<typename T>
void AizoArray<T>::heapSort() {
    HeapSort<T>::heapSort(this->aizoArray, this->aizoArraySize);
}

template<typename T>
void AizoArray<T>::shellSort(char type) {

    typename ShellSort<T>::shellType shellType;
    switch (type) {
        case 'K':
            shellType = ShellSort<T>::KNUTH;
            break;
        case 'H':
            shellType = ShellSort<T>::HIBBARD;
            break;
        default:
            throw std::invalid_argument("Invalid shell sort type");
    }

    ShellSort<T>::sort(this->aizoArray, this->aizoArraySize, shellType);
}