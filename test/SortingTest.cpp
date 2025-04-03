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
    bool isSorted(const AizoArray<T>& arr) {
        for (size_t i = 1; i < arr.size(); i++) {
            if (arr[i-1] > arr[i]) {
                return false;
            }
        }
        return true;
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

        // Zapamiętaj pierwotną tablicę przed sortowaniem
        std::string beforeSort = captureOutput([&a]() { a.print(); });

        // Wykonaj sortowanie szybkie
        a.quickSort();

        // Sprawdź czy tablica jest posortowana
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

        // Zapamiętaj pierwotną tablicę przed sortowaniem
        std::string beforeSort = captureOutput([&a]() { a.print(); });

        // Wykonaj sortowanie przez wstawianie
        a.insertionSort();

        // Sprawdź czy tablica jest posortowana
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

        // Zapamiętaj pierwotną tablicę przed sortowaniem
        std::string beforeSort = captureOutput([&a]() { a.print(); });

        // Wykonaj sortowanie przez wstawianie
        a.heapSort();

        // Sprawdź czy tablica jest posortowana
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

        return result;
    }
};