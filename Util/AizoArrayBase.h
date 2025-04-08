// Klasa abstrakcyjna do budowy AizoArray

#ifndef AIZOARRAYBASE_H
#define AIZOARRAYBASE_H

class AizoArrayBase {
public:
    virtual ~AizoArrayBase() = default;
    virtual void print() = 0;
    virtual void printPrimary() = 0;
    virtual void reshamble() = 0;
    virtual void clear() = 0;

    virtual void reserve(size_t size) = 0;
    virtual bool isSorted() = 0;
    virtual size_t size() const = 0;

    virtual void quickSort(char) = 0;
    virtual void insertionSort()= 0;
    virtual void heapSort()= 0;
    virtual void shellSort(char)= 0;
};

#endif // AIZOARRAYBASE_H