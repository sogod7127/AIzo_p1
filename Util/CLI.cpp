// CLI do prowadzenia statystyk

#include <algorithm>
#include <bemapiset.h>
#include <ctime>
#include <iostream>
#include <memory>
#include <numeric>
#include <windows.h>
#include <cmath>

#include "AizoArrayBase.h"
#include "File/FileUtill.h"
#include "File/ResultSaver.h"



class CLI {
    float PCFreq = 0.0;
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
                }else if (choice == 4) {
                       runSimulation();
                }
                else if (choice == 0) {
                    exit(0);
                }
                else {
                    std::cerr << "Nieprawidłowy wybór.\n";

                }

        if (choice == 2 || choice == 1) {
            ResultSaver saver("../results.txt");

            std::cout << "Wyniki:\n " << std::endl;
            std::cout << "Quick Sort:\n";
            std::cout << "  Pivot po lewo - ";
            // Przykład dla Quick Sort
            std::cout << "Quick Sort:\n";
            std::cout << "  Pivot po lewo - ";
            StartCounter();
            array->quickSort('L');
            PrintCounterWithSave(saver, "QS-L");
            array->reshamble();

            std::cout << "  Pivot po prawo - ";
            StartCounter();
            array->quickSort('R');
            PrintCounterWithSave(saver, "QS_R");
            array->reshamble();

            std::cout << "  Pivot na srodku - ";
            StartCounter();
            array->quickSort('M');
            PrintCounterWithSave(saver, "QS_M");
            array->reshamble();

            std::cout << "  Pivot losowo - ";
            StartCounter();
            array->quickSort('r');
            PrintCounterWithSave(saver, "QS_r");
            array->reshamble();

            std::cout << "Insertion Sort - ";
            StartCounter();
            array->insertionSort();
            PrintCounterWithSave(saver, "IS");
            array->reshamble();

            std::cout << "Heap Sort - ";
            StartCounter();
            array->heapSort();
            PrintCounterWithSave(saver, "HS");
            array->reshamble();

            std::cout << "Shell Sort:\n";
            std::cout << "  Hibbard Sort - ";
            StartCounter();
            array->shellSort('H');
            PrintCounterWithSave(saver, "SS-H");
            array->reshamble();
            std::cout << "  Knuth Sort - ";
            StartCounter();
            array->shellSort('K');
            PrintCounterWithSave(saver, "SS-K");
            array->reshamble();
        }
    }

        void printMenu() {
            std::cout << "Wybierz opcje:\n";
            std::cout << "1. Wygeneruj losowe liczby\n";
            std::cout << "2. Wczytaj liczby z pliku\n";
            std::cout << "3. Przywroc tablice pierwotną\n";
            std::cout << "4. Uruchom symulacje\n";
            std::cout << "0. Wyjdz\n";
        }

    void StartCounter() {
        LARGE_INTEGER li;
        if (!QueryPerformanceFrequency(&li))
            std::cout << "QueryPerformanceFrequency failed!\n";

        PCFreq = float(li.QuadPart) / 1000.0;

        QueryPerformanceCounter(&li);
        CounterStart = li.QuadPart;
    }

    void PrintCounter() {
        LARGE_INTEGER li;
        QueryPerformanceCounter(&li);
        std::cout << "Czas: " << float(li.QuadPart - CounterStart) / PCFreq << " ms\n";
    }

    void PrintCounterWithSave(ResultSaver& saver, const std::string& prefix) {
        LARGE_INTEGER li;
        QueryPerformanceCounter(&li);
        float time = float(li.QuadPart - CounterStart) / PCFreq;
        std::cout << "Czas: " << time << " ms\n";
        saver.saveResult(prefix, time);
    }


void runSimulation() {
    int size;
    std::cout << "Podaj rozmiar tablicy: ";
    std::cin >> size;

    AizoArray<float> qs_L_times(100), qs_R_times(100), qs_M_times(100),qs_r_times(100), is_times(100), hs_times(100), ss_h_times(100), ss_k_times(100);
    std::cout << "Symulacja trwa, proszę czekać...\n";
    for (int i = 0; i < 100; ++i) {
        std::unique_ptr<AizoArrayBase> array_t = std::make_unique<AizoArray<int>>();
        generateRandomNumbers(array_t, size);
        std::cout << "Symulacja " << i + 1 << " z 100\n";

        StartCounter();
        array_t->quickSort('L');
        qs_L_times.push_back(getElapsedTime());
        array_t->reshamble();
        
        StartCounter();
        array_t->quickSort('R');
        qs_R_times.push_back(getElapsedTime());
        array_t->reshamble();

        StartCounter();
        array_t->quickSort('M');
        qs_M_times.push_back(getElapsedTime());
        array_t->reshamble();

        StartCounter();
        array_t->quickSort('r');
        qs_r_times.push_back(getElapsedTime());
        array_t->reshamble();

        StartCounter();
        array_t->insertionSort();
        is_times.push_back(getElapsedTime());
        array_t->reshamble();

        StartCounter();
        array_t->heapSort();
        hs_times.push_back(getElapsedTime());
        array_t->reshamble();

        StartCounter();
        array_t->shellSort('H');
        ss_h_times.push_back(getElapsedTime());
        array_t->reshamble();

        StartCounter();
        array_t->shellSort('K');
        ss_k_times.push_back(getElapsedTime());
        array_t->reshamble();

        array_t.get_deleter();
    }

    saveResultsToFile("QS_L_results.txt", qs_L_times);
    saveResultsToFile("QS_R_results.txt", qs_R_times);
    saveResultsToFile("QS_M_results.txt", qs_M_times);
    saveResultsToFile("QS_r_results.txt", qs_r_times);
    saveResultsToFile("IS_results.txt", is_times);
    saveResultsToFile("HS_results.txt", hs_times);
    saveResultsToFile("SS_H_results.txt", ss_h_times);
    saveResultsToFile("SS_K_results.txt", ss_k_times);

    saveStatisticsToFile("statistics.txt", qs_L_times, "QS_L");
    saveStatisticsToFile("statistics.txt", qs_R_times, "QS_R");
    saveStatisticsToFile("statistics.txt", qs_M_times, "QS_M");
    saveStatisticsToFile("statistics.txt", qs_r_times, "QS_r");
    saveStatisticsToFile("statistics.txt", is_times, "IS");
    saveStatisticsToFile("statistics.txt", hs_times, "HS");
    saveStatisticsToFile("statistics.txt", ss_h_times, "SS_H");
    saveStatisticsToFile("statistics.txt", ss_k_times, "SS_K");

        qs_L_times.clear();
        qs_R_times.clear();
        qs_M_times.clear();
        qs_r_times.clear();
        is_times.clear();
        hs_times.clear();
        ss_h_times.clear();
        ss_k_times.clear();

    }

void saveResultsToFile(const std::string& filename, const AizoArray<float>& times) {
    std::ofstream file("../Wyniki/" + filename);
    for (size_t i = 0; i < times.size(); ++i) {
        file << times[i] << "\n";
    }
}

void saveStatisticsToFile(const std::string& filename, AizoArray<float>& times, const std::string& prefix) {
    std::ofstream file("../Wyniki/" + filename, std::ios::app);

    float sum = 0.0;
    for (size_t i = 0; i < times.size(); ++i) {
       sum += times[i];
    }
    float mean = sum / times.size();

    times.quickSort('R');
    float median = times[times.size() / 2];

    float sq_sum = 0.0;
    for (size_t i = 0; i < times.size(); ++i) {
        sq_sum += times[i] * times[i];
    }
    float stdev = std::sqrt(sq_sum / times.size() - mean * mean);

    file << prefix << " - Średnia: " << mean << " ms, Mediana: " << median << " ms, Odchylenie standardowe: " << stdev << " ms\n";
}

    float getElapsedTime() {
        LARGE_INTEGER li;
        QueryPerformanceCounter(&li);
        float ans = (li.QuadPart - CounterStart) / PCFreq;
        return ans;
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
