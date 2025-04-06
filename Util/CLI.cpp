// CLI do prowadzenia statystyk

#include <bemapiset.h>
#include <ctime>
#include <iostream>
#include <memory>
#include <windows.h>

#include "AizoArrayBase.h"
#include "File/FileUtill.h"

class CLI {
    double PCFreq = 0.0;
    __int64 CounterStart = 0;
    std::unique_ptr<AizoArrayBase> array;

public:
    void run() {
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
                    std::cout << "Podaj sciezkie pliku: ";
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

        std::cout << "Wyniki:\n " << std::endl;
        std::cout << "Quick Sort:\n";
        std::cout << "  Pivot po lewo - ";
        StartCounter();
        array->quickSort('L');
        PrintCounter();
        array->reshamble();
        std::cout << "  Pivot po prawo - ";
        StartCounter();
        array->quickSort('R');
        PrintCounter();
        array->reshamble();
        std::cout << "  Pivot na srodku - ";
        StartCounter();
        array->quickSort('M');
        PrintCounter();
        array->reshamble();
        std::cout << "  Pivot losowo - ";
        StartCounter();
        array->quickSort('r');
        PrintCounter();
        array->reshamble();
        std:: cout << "Insertion Sort - ";
        StartCounter();
        array->insertionSort();
        PrintCounter();
        array->reshamble();
        std::cout << "Heap Sort - ";
        StartCounter();
        array->heapSort();
        PrintCounter();
        array->reshamble();
        std::cout << "Shell Sort:\n";
        std::cout << "  Hibbard Sort - ";
        StartCounter();
        array->shellSort('H');
        PrintCounter();
        array->reshamble();
        std::cout << "  Knuth Sort - ";
        StartCounter();
        array->shellSort('K');
        PrintCounter();
        array->reshamble();
    }

        void printMenu() {
            std::cout << "Wybierz opcje:\n";
            std::cout << "1. Wygeneruj losowe liczby\n";
            std::cout << "2. Wczytaj liczby z pliku\n";
            std::cout << "0. Wyjdz\n";
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

    void generateRandomNumbers(std::unique_ptr<AizoArrayBase>& array, int count) {

        auto array2 = std::make_unique<AizoArray<int>>();

        array2->reserve(count);

        std::srand(std::time(nullptr));
        for (int i = 0; i < count; ++i) {
            array2 -> push_back(std::rand() % 100);
        }

        array = std::move(array2);
    }
};
