cmake_minimum_required(VERSION 3.30)
project(AIzo_p1)

set(CMAKE_CXX_STANDARD 20)

# Main application
add_executable(AIzo_p1 main.cpp
        Util/AizoArray.tpp
        Util/AizoArray.h
        lib.h
        Util/Sorting/QuickSort.h
        Util/Sorting/InsertionSort.tpp
        Util/Sorting/InsertionSort.h
        Util/Sorting/HeapSort.tpp
        Util/Sorting/HeapSort.h
)

# Test executable
add_executable(AIzo_tests
        test/AizoArrayTest.cpp
        test/TestRunner.cpp
        Util/AizoArray.tpp
        Util/AizoArray.h
        lib.h
        test/AizoArrayTest.cpp
        test/TestRunner.cpp
        Util/Sorting/QuickSort.tpp
        Util/Sorting/QuickSort.h
        Util/Sorting/InsertionSort.tpp
        Util/Sorting/InsertionSort.h
        test/SortingTest.cpp
)