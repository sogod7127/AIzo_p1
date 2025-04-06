//Test do sortowania

#include <iostream>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include "../Util/AizoArray.h"

class SortedArrayTest {
private:
    // Helper function to capture console output
    std::string captureOutput(const std::function<void()>& func) {
        std::stringstream buffer;
        std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());
        func();
        std::cout.rdbuf(oldBuffer);
        return buffer.str();
    }

    // Helper function to check if array is sorted
    template<typename T>
    bool isSorted(AizoArray<T>& arr) {
        return arr.isSorted();
    }

public:
    bool testArrayInitialization() {
        std::cout << "Running testArrayInitialization..." << std::endl;

        int arr[] = {45, 12, 67, 3, 89, 22, 56, 14, 78, 90, 21, 34, 8, 54, 73, 50, 11, 5, 42, 61};
        AizoArray<int> a(arr);

        bool sizeCheck = (a.size() == 20);
        std::string output = captureOutput([&a]() { a.print(); });

        std::cout << (sizeCheck ? "PASSED" : "FAILED") << std::endl;
        return sizeCheck;
    }

    bool testQuickSort() {
        std::cout << "Running testQuickSort..." << std::endl;

        int arr[] = {45, 12, 67, 3, 89, 22, 56, 14, 78, 90, 21, 34, 8, 54, 73, 50, 11, 5, 42, 61};
        AizoArray<int> a(arr);

        std::string beforeSort = captureOutput([&a]() { a.print(); });

        a.quickSort();

        bool sortCheck = isSorted(a);
        std::string afterSort = captureOutput([&a]() { a.print(); });

        std::cout << "Before: " << beforeSort;
        std::cout << "After:  " << afterSort;
        std::cout << (sortCheck ? "PASSED" : "FAILED") << std::endl;

        return sortCheck;
    }

    bool testInsertionSort() {
        std::cout << "Running testInsertionSort..." << std::endl;

        int arr[] = {45, 12, 67, 3, 89, 22, 56, 14, 78, 90, 21, 34, 8, 54, 73, 50, 11, 5, 42, 61};
        AizoArray<int> a(arr);

        std::string beforeSort = captureOutput([&a]() { a.print(); });

        a.insertionSort();

        bool sortCheck = isSorted(a);
        std::string afterSort = captureOutput([&a]() { a.print(); });

        std::cout << "Before: " << beforeSort;
        std::cout << "After:  " << afterSort;
        std::cout << (sortCheck ? "PASSED" : "FAILED") << std::endl;

        return sortCheck;
    }

    bool testHeapSort() {
        std::cout << "Running testInsertionSort..." << std::endl;

        int arr[] = {45, 12, 67, 3, 89, 22, 56, 14, 78, 90, 21, 34, 8, 54, 73, 50, 11, 5, 42, 61};
        AizoArray<int> a(arr);

        std::string beforeSort = captureOutput([&a]() { a.print(); });

        a.heapSort();

        bool sortCheck = isSorted(a);
        std::string afterSort = captureOutput([&a]() { a.print(); });

        std::cout << "Before: " << beforeSort;
        std::cout << "After:  " << afterSort;
        std::cout << (sortCheck ? "PASSED" : "FAILED") << std::endl;

        return sortCheck;
    }


    bool testShellSort(){
        std::cout << "Running testShellSort..." << std::endl;

        int arr[] = {45, 12, 67, 3, 89, 22, 56, 14, 78, 90, 21, 34, 8, 54, 73, 50, 11, 5, 42, 61};
        AizoArray<int> a(arr);

        std::string beforeSort = captureOutput([&a]() { a.print(); });

        a.shellSort('K');

        bool sortCheck = isSorted(a);
        std::string afterSort = captureOutput([&a]() { a.print(); });

        std::cout << "Before: " << beforeSort;
        std::cout << "After:  " << afterSort;
        std::cout << (sortCheck ? "PASSED" : "FAILED") << std::endl;

        return sortCheck;
    }

    bool runAllTests() {
        bool result = true;
        result &= testArrayInitialization();
        result &= testQuickSort();
        result &= testInsertionSort();
        result &= testHeapSort();
        result &= testShellSort();

        return result;
    }
};