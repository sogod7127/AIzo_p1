//Generowanie plików testowych do TestNumbers

//int_data.txt <- tylko integery
//float_data.txt <- tylko floaty
//mix_data.txt <- floaty i integery

#include <filesystem>
#include <fstream>
#include <iomanip>
#include <stdexcept>

const int NUM_ELEMENTS = 10000;

void createIntFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    file << NUM_ELEMENTS;

    // Liczby całkowite
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        file << std::endl;
        file << std::rand() % 1000000;
    }

    file.close();
}

void createFloatFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    file << NUM_ELEMENTS;

    // Liczby zmiennoprzecinkowe
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        file << std::endl;
        file << std::fixed << std::setprecision(2) << static_cast<float>(std::rand() % 10000) / 1000000.0; // Liczby zmiennoprzecinkowe od 0.00 do 99.99
    }

    file.close();
}

void createMixedFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    file << NUM_ELEMENTS;

    // Mieszane liczby
    for (int i = 1; i <= NUM_ELEMENTS; ++i) {
        file << std::endl;
        if (i % 2 == 0) {
            file << i; // Liczba całkowita
        } else {
            file << std::fixed << std::setprecision(2) << i + 0.5; // Liczba zmiennoprzecinkowa
        }
    }

    file.close();
}

void createAscendingFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    file << NUM_ELEMENTS;

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        file << std::endl;
        file << i;
    }

    file.close();
}

void createDescendingFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    file << NUM_ELEMENTS;

    for (int i = NUM_ELEMENTS; i > 0; --i) {
        file << std::endl;
        file << i;
    }

    file.close();
}

void createPartiallySortedFile(const std::string& filename, double sortedPercentage) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    file << NUM_ELEMENTS;

    int sortedElements = static_cast<int>(NUM_ELEMENTS * sortedPercentage);
    for (int i = 0; i < sortedElements; ++i) {
        file << std::endl;
        file << i;
    }

    for (int i = sortedElements; i < NUM_ELEMENTS; ++i) {
        file << std::endl;
        file << std::rand() % 1000000;
    }

    file.close();
}

int main() {
    std::filesystem::create_directory("TestNumbers");

    createIntFile("TestNumbers/int_data.txt");
    createFloatFile("TestNumbers/float_data.txt");
    createMixedFile("TestNumbers/mixed_data.txt");
    createAscendingFile("TestNumbers/ascending_data.txt");
    createDescendingFile("TestNumbers/descending_data.txt");
    createPartiallySortedFile("TestNumbers/partially_sorted_66_data.txt", 0.66);
    createPartiallySortedFile("TestNumbers/partially_sorted_33_data.txt", 0.33);

    return 0;
}