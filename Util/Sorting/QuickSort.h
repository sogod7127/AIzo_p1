


#ifndef QUICKSORT_H
#define QUICKSORT_H

template <typename T>
class QuickSort {
public:
    enum PivotType{
        LEFT,
        RIGHT,
        RANDOM,
        MIDDLE
    };
    static void sort(T arr[], size_t arr_size, PivotType pivot = RIGHT);
    private:

    static PivotType currentPivotType;
    static void swap(T& a, T& b);
    static int partition(T* array, int low, int high);
    static void insideQuickSort(T* array, int low, int high);

};

#endif //QUICKSORT_H
