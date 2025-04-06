//Własny vector

#include "AizoArrayBase.h"
#include <type_traits>
#include "Sorting/QuickSort.h"

#ifndef AIZO_ARRAY_H
#define AIZO_ARRAY_H
template <typename T>
class AizoArray : public AizoArrayBase
{
private:
    T* aizoArray; //Miejsce robocze do sortowania
    T* primaryAizo; // Array ktory mial pierwotna tablice
    size_t aizoArraySize;
    size_t reservedSize;

public:
    AizoArray();
    AizoArray(T arr[], size_t arr_size);
    template <size_t N>
    AizoArray(T (&arr)[N]);
    AizoArray(int dummy);

    ~AizoArray()override {
        delete[] aizoArray;
    }

    void push_back(T value);
    void quickSort(char = 'R');
    void insertionSort();
    void heapSort();
    void shellSort(char);
    void print() override;
    void printPrimary()override;
    void reserve(size_t size) override;
    void reshamble() override; // Restartuje tablice robocza do pierwotnej

    bool isSorted() override;


    size_t size() const override;
    T& operator[](size_t index);

    const T& operator[](size_t index) const;
};


#include "AizoArray.tpp"

#endif //AIZO_ARRAY_H