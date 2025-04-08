


#include <fstream>
#include <string>


#include "ResultSaver.h"



    ResultSaver::ResultSaver(const std::string &filename) {
        file.open(filename, std::ios::out | std::ios::app);
        if (!file.is_open()) {
            throw std::runtime_error("Nie można otworzyć pliku do zapisu.");
        }
    }

    ResultSaver::~ResultSaver() {
        if (file.is_open()) {
            file.close();
        }
    }

    void ResultSaver::saveResult(const std::string& prefix, double time) {
        if (file.is_open()) {
            file << prefix << ": " << time << " ms" << std::endl;
        }
    }


