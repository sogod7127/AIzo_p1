//
// Created by skwasnik on 06.04.2025.
//

#include "FileUtill.h"

#include <memory>
#include <fstream>
#include <iomanip>
#include <limits>


std::unique_ptr<AizoArrayBase> FileUtill::loadFromFile(const std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    int size;
    file >> size;
    if (size <= 0) {
        throw std::runtime_error("Invalid array size");
    }

    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Przesuń wskaźnik pliku do nowej linii

    std::string line;
    std::getline(file, line); // Read the rest of the first line

    std::istringstream iss(line);
    int intValue;
    float floatValue;
    char charValue;

    //TODO: Make code more clear
    std::unique_ptr<AizoArrayBase> arr;
    // Try to read as int
    if (iss >> intValue && iss.eof()) {
        arr = FileUtill::readArrayFromFile<int>(file, size);
    } else {
        iss.clear();
        iss.str(line);
        // Try to read as float
        if (iss >> floatValue && iss.eof()) {
            arr = FileUtill::readArrayFromFile<float>(file, size);
        } else {
            iss.clear();
            iss.str(line);
            // Try to read as char
            if (iss >> charValue && iss.eof()) {
                arr = FileUtill::readArrayFromFile<char>(file, size);
            } else {
                throw std::runtime_error("Unsupported data type");
            }
        }
    }

    return arr;
}

template<typename T>
std::unique_ptr<AizoArray<T>> FileUtill::readArrayFromFile(std::ifstream& file, int size) {
    auto arrAZ = std::make_unique<AizoArray<T>>();
    arrAZ->reserve(size);

    for (int i = 0; i < size; ++i) {
        T value;
        if (file.eof())
            break;
        if (!(file >> value)) {
            throw std::runtime_error("Error reading array elements");
        }
        arrAZ->push_back(value);
    }
    return arrAZ;
}