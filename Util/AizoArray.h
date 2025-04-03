// AizoArray.h

#include <type_traits>


#ifndef AIZO_ARRAY_H
#define AIZO_ARRAY_H
template <typename T>
class AizoArray
{
private:
    T* aizoArray;
    size_t aizoArraySize;
    size_t reservedSize;
    void reserve(size_t size);
public:
    AizoArray();

    AizoArray(T arr[], size_t arr_size);

    template <size_t N>
    AizoArray(T (&arr)[N]);

    AizoArray(int dummy);


    void push_back(T value);
    void quickSort();
    void insertionSort();
    void heapSort();
    void print();

    size_t size() const;
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
};


#include "AizoArray.tpp"

#endif //AIZO_ARRAY_H