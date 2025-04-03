#include <iostream>
#include "Util/AizoArray.h"

int main() {

    int arr[] = {45, 12, 67, 3, 89, 22, 56, 14, 78, 90, 21, 34, 8, 54, 73, 50, 11, 5, 42, 61};

    AizoArray<int> a(arr);

    std::cout<<"Heap Sort: \n" << std::endl;
    a.print();

    a.heapSort();
    a.print();



    return 0;
}
