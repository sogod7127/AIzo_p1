//Simple load file system

#ifndef FILEUTILL_H
#define FILEUTILL_H
#include <memory>

#include "../AizoArray.h"


class FileUtill {
public:
    static std::unique_ptr<AizoArrayBase>loadFromFile(const std::string filename);
    template<typename T>
    static std::unique_ptr<AizoArray<T>> readArrayFromFile(std::ifstream& file, int size);
};



#endif //FILEUTILL_H
