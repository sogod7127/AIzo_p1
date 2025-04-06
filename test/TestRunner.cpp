//Glowny plik do uruchamiania prostych testow

#include <iostream>
#include <string>
#include "AizoArrayTest.cpp"
#include "SortingTest.cpp"  // Dodajemy nowy test

int main(int argc, char* argv[]) {
    AizoArrayTest aizoTester;
    SortedArrayTest sortedTester;  // Instancja nowego testera

    if (argc > 1) {
        std::string testName = argv[1];

        if (testName == "default") {
            return aizoTester.testDefaultConstructor() ? 0 : 1;
        }
        else if (testName == "deduction") {
            return aizoTester.testArrayConstructorWithDeduction() ? 0 : 1;
        }
        else if (testName == "explicit") {
            return aizoTester.testArrayConstructorWithSize() ? 0 : 1;
        }
        else if (testName == "quicksort") {
            return sortedTester.testQuickSort() ? 0 : 1;
        }
        else if (testName == "insertionsort") {
            return sortedTester.testInsertionSort() ? 0 : 1;
        }
        else {
            std::cout << "Unknown test: " << testName << std::endl;
            return 1;
        }
    }

    // Run all tests if no specific test is specified
    bool aizoTestsPassed = aizoTester.runAllTests();
    bool sortedTestsPassed = sortedTester.runAllTests();  // Uruchamiamy również nowe testy
    bool allPassed = aizoTestsPassed && sortedTestsPassed;

    std::cout << "\n=== TEST RESULTS ===\n";
    std::cout << (allPassed ? "ALL TESTS PASSED" : "SOME TESTS FAILED") << std::endl;
    return allPassed ? 0 : 1;
}