#ifndef RESULT_SAVER_H
#define RESULT_SAVER_H

#include <fstream>
#include <string>

class ResultSaver {
    std::ofstream file;

public:
    ResultSaver(const std::string& filename);
    ~ResultSaver();

    void saveResult(const std::string& prefix, double time);
};

#endif //RESULT_SAVER_H