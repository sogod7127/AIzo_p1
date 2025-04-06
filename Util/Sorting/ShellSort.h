
#ifndef SHELLSORT_H
#define SHELLSORT_H

template<typename T>
class ShellSort {

public:
    enum shellType{
        KNUTH,
        HIBBARD
    };
    static void sort(T arr[], size_t n, shellType type = KNUTH);

private:
    static void knuthSort(T array[], size_t n);
    static void hibbardSort(T array[], size_t n);
};

#endif //SHELLSORT_H
