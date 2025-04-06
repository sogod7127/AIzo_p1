#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "test/TestCLI.cpp"
#include "Util/CLI.cpp"

bool isTestingModeEnabled(const std::string& configFilePath) {
    std::ifstream configFile(configFilePath);
    if (!configFile.is_open()) {
        std::cerr << "Nie można otworzyć pliku konfiguracyjnego: " << configFilePath << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(configFile, line)) {
        std::istringstream lineStream(line);
        std::string key;
        if (std::getline(lineStream, key, '=')) {
            std::string value;
            if (std::getline(lineStream, value)) {
                if (key == "testing_mode") {
                    return value == "true";
                }
            }
        }
    }

    return false;
}

int main() {
    const std::string configFilePath = "../config.conf";
    if (isTestingModeEnabled(configFilePath)) {
        TestCLI test;
        test.run();
    } else {
        CLI cli;
        cli.run();
    }
    return 0;
}