// CLI ze srodowiskiem do testowania

#include <ctime>
#include <iostream>
#include <windows.h>

#include "../Util/AizoArray.h"
#include "../Util/AizoArrayBase.h"
#include "../Util/File/FileUtill.h"

class TestCLI {

    double PCFreq = 0.0;
    __int64 CounterStart = 0;

public:

    std::unique_ptr<AizoArrayBase> array;

    void run() {
        while (true) {
            int choice;
            printMenu();
            std::cin >> choice;

            if (choice == 1) {
                int count;
                std::cout << "Podaj ilosc liczb do wygenerowania: ";
                std::cin >> count;
                generateRandomNumbers(array, count);
            } else if (choice == 2) {
                std::string filename;
                std::cout << "Podaj nazwe pliku: ";
                std::cin >> filename;
                array = FileUtill::loadFromFile(filename);
            } else if (choice ==3) {
                array -> reshamble(); //kopiuje primary do posortowanej
                //TODO: improve how to have primary table
            } else if (choice == 0) {
                exit(0);
            }
            else {
                std::cerr << "Nieprawidłowy wybór.\n";

            }

            std::cout << "Tablica: " << std::endl;
            array->print();
            std::cout << std::endl;

            chooseAlorithm();
            std::cout << "Wybierz algorytm sortowania: ";
            std::cin >> choice;

            switch (choice) {
                case 1: {
                    char pivotType;
                    printPivotMenu();
                    std::cin >> pivotType;
                    StartCounter();
                    array->quickSort(pivotType);
                    PrintCounter();
                    break;
                }
                case 2:
                    StartCounter();
                array->insertionSort();
                PrintCounter();
                break;
                case 3:
                    StartCounter();
                array->heapSort();
                PrintCounter();
                break;
                case 4: {
                    char shellType;
                    std::cout << "Wybierz typ Shell Sort (K - Knuth, H - Hibbard): ";
                    std::cin >> shellType;
                    StartCounter();
                    array->shellSort(shellType);
                    PrintCounter();
                    break;
                }
                default:
                    std::cerr << "Nieprawidłowy wybór.\n";

            }

            if (array->size()<=50) {
                std::cout << "Przed posortowaniem:\n";
                array->printPrimary();

                std::cout << "Posortowane liczby:\n";
                array->print();
            }
            else {
                std::cout << "Tablica zbyt duza, aby ja wyswietlic.\n";
            }

            std::cout << "Brute force czy posortowane..." << std::endl;
            std::cout << "Czy tablica jest posortowana? " << (array->isSorted() ? "Tak" : "Nie") << std::endl;
        }
    }
private:

    void generateRandomNumbers(std::unique_ptr<AizoArrayBase>& array, int count) {

        auto array2 = std::make_unique<AizoArray<int>>();

        array2->reserve(count);

        std::srand(std::time(nullptr));
        for (int i = 0; i < count; ++i) {
            array2 -> push_back(std::rand() % 100);
        }

        array = std::move(array2);
    }

    void printMenu() {
        std::cout << "Wybierz opcje:\n";
        std::cout << "1. Wygeneruj losowe liczby\n";
        std::cout << "2. Wczytaj liczby z pliku\n";
        if (array) {
            std::cout << "3. Wykonaj sortowanie na starej tablicy\n";
        }
        std::cout << "0. Wyjdz\n";
    }

    void chooseAlorithm() {
        std::cout << "Wybierz algorytm sortowania:\n";
        std::cout << "1. Quick Sort\n";
        std::cout << "2. Insertion Sort\n";
        std::cout << "3. Heap Sort\n";
        std::cout << "4. Shell Sort\n";
    }

    void printPivotMenu() {
        std::cout << "Wybierz typ pivotu dla Quick Sort:\n";
        std::cout << "L - Lewy\n";
        std::cout << "R - Prawy\n";
        std::cout << "M - Srodkowy\n";
        std::cout << "r - Losowy\n";
    }

    void StartCounter() {
        LARGE_INTEGER li;
        if (!QueryPerformanceFrequency(&li))
            std::cout << "QueryPerformanceFrequency failed!\n";

        PCFreq = double(li.QuadPart) / 1000.0;

        QueryPerformanceCounter(&li);
        CounterStart = li.QuadPart;
    }

    void PrintCounter() {
        LARGE_INTEGER li;
        QueryPerformanceCounter(&li);
        std::cout << "Czas: " << double(li.QuadPart - CounterStart) / PCFreq << " ms\n";
    }

};