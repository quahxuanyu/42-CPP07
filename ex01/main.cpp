#include "iter.hpp"
#include <iostream>
#include <string>

// Test functions for int arrays
void incrementInt(int &n) {
    n++;
}

void printInt(int &n) {
    std::cout << n << " ";
}

void printConstInt(const int &n) {
    std::cout << n << " ";
}

// Test functions for double arrays
void doubleValue(double &n) {
    n *= 2;
}

void printDouble(double &n) {
    std::cout << n << " ";
}

// Test functions for string arrays
void toUpperCase(std::string &str) {
    for (size_t i = 0; i < str.length(); i++) {
        str[i] = std::toupper(str[i]);
    }
}

void printString(std::string &str) {
    std::cout << str << " ";
}

void printConstString(const std::string &str) {
    std::cout << str << " ";
}

// Test function for char arrays
void printChar(char &c) {
    std::cout << c;
}

void printConstChar(const char &c) {
    std::cout << c;
}

// Generic template function
template <typename T>
void printElement(T &element) {
    std::cout << element << " ";
}

template <typename T>
void printConstElement(const T &element) {
    std::cout << element << " ";
}

int main() {
    std::cout << "=== Test 1: Integer array with non-const function ===" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = 5;
    
    std::cout << "Original array: ";
    iter(intArray, intSize, printInt);
    std::cout << std::endl;
    
    std::cout << "After incrementing: ";
    iter(intArray, intSize, incrementInt);
    iter(intArray, intSize, printInt);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 2: Integer array with const function ===" << std::endl;
    const int constIntArray[] = {10, 20, 30, 40, 50};
    std::cout << "Const array: ";
    iter(constIntArray, 5, printConstInt);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 3: Double array ===" << std::endl;
    double doubleArray[] = {1.5, 2.5, 3.5, 4.5};
    size_t doubleSize = 4;
    
    std::cout << "Original array: ";
    iter(doubleArray, doubleSize, printDouble);
    std::cout << std::endl;
    
    std::cout << "After doubling: ";
    iter(doubleArray, doubleSize, doubleValue);
    iter(doubleArray, doubleSize, printDouble);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 4: String array ===" << std::endl;
    std::string stringArray[] = {"hello", "world", "cpp", "templates"};
    size_t stringSize = 4;
    
    std::cout << "Original array: ";
    iter(stringArray, stringSize, printString);
    std::cout << std::endl;
    
    std::cout << "After converting to uppercase: ";
    iter(stringArray, stringSize, toUpperCase);
    iter(stringArray, stringSize, printString);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 5: Const string array ===" << std::endl;
    const std::string constStringArray[] = {"const", "string", "test"};
    std::cout << "Const string array: ";
    iter(constStringArray, 3, printConstString);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 6: Char array ===" << std::endl;
    char charArray[] = {'H', 'e', 'l', 'l', 'o', '!'};
    std::cout << "Char array: ";
    iter(charArray, 6, printChar);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 7: Using template function ===" << std::endl;
    int testArray[] = {100, 200, 300};
    std::cout << "Using generic template function: ";
    iter(testArray, 3, printElement<int>);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 8: Empty array (edge case) ===" << std::endl;
    int emptyArray[] = {};
    std::cout << "Empty array (size 0): ";
    iter(emptyArray, 0, printInt);
    std::cout << "(nothing should print)" << std::endl << std::endl;

    std::cout << "=== Test 9: Single element array ===" << std::endl;
    int singleArray[] = {42};
    std::cout << "Single element: ";
    iter(singleArray, 1, printInt);
    std::cout << std::endl << std::endl;

    std::cout << "All tests completed!" << std::endl;

    return 0;
}
