// Testy do budowania Arrayow

#include <iostream>
#include <cassert>
#include <sstream>
#include <functional>
#include "../Util/AizoArray.h"

class AizoArrayTest {
private:
    // Helper function to capture console output
    std::string captureOutput(const std::function<void()>& func) {
        std::stringstream buffer;
        std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());
        func();
        std::cout.rdbuf(oldBuffer);
        return buffer.str();
    }

public:
    bool testDefaultConstructor() {
        std::cout << "Running testDefaultConstructor..." << std::endl;
        
        AizoArray<int> c;
        c.push_back(45);
        
        bool sizeCheck = (c.size() == 1);
        std::string output = captureOutput([&c]() { c.print(); });
        bool outputCheck = (output == "45\n");
        
        std::cout << (sizeCheck && outputCheck ? "PASSED" : "FAILED") << std::endl;
        return sizeCheck && outputCheck;
    }
    
    bool testArrayConstructorWithDeduction() {
        std::cout << "Running testArrayConstructorWithDeduction..." << std::endl;
        
        int arr[] = {1, 2, 3, 4, 5};
        AizoArray<int> a(arr);
        
        bool sizeCheck = (a.size() == 5);
        std::string output = captureOutput([&a]() { a.print(); });
        bool outputCheck = (output == "1, 2, 3, 4, 5\n");
        
        std::cout << (sizeCheck && outputCheck ? "PASSED" : "FAILED") << std::endl;
        return sizeCheck && outputCheck;
    }
    
    bool testArrayConstructorWithSize() {
        std::cout << "Running testArrayConstructorWithSize..." << std::endl;
        
        float arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
        AizoArray<float> b(arr2, 5);
        b.push_back(5);
        
        bool sizeCheck = (b.size() == 6);
        std::string output = captureOutput([&b]() { b.print(); });
        bool outputCheck = (output == "1.1, 2.2, 3.3, 4.4, 5.5, 5\n");
        
        std::cout << (sizeCheck && outputCheck ? "PASSED" : "FAILED") << std::endl;
        return sizeCheck && outputCheck;
    }
    
    bool runAllTests() {
        bool result = true;
        result &= testDefaultConstructor();
        result &= testArrayConstructorWithDeduction();
        result &= testArrayConstructorWithSize();
        return result;
    }
};