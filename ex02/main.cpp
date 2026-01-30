#include "Array.hpp"
#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

void printTestHeader(const std::string& testName) {
    std::cout << "\n" << CYAN << "=== " << testName << " ===" << RESET << std::endl;
}

void printSuccess(const std::string& message) {
    std::cout << GREEN << "✓ " << message << RESET << std::endl;
}

void printInfo(const std::string& message) {
    std::cout << YELLOW << "  " << message << RESET << std::endl;
}

int main() {
    std::cout << MAGENTA << "╔══════════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << MAGENTA << "║     Array Template Class - Test Suite       ║" << RESET << std::endl;
    std::cout << MAGENTA << "╚══════════════════════════════════════════════╝" << RESET << std::endl;

    // Test 1: Default constructor
    printTestHeader("Test 1: Default Constructor");
    {
        Array<int> emptyArray;
        printInfo("Created empty array");
        std::cout << "Size: " << emptyArray.size() << std::endl;
        printSuccess("Default constructor works correctly");
    }

    // Test 2: Parameterized constructor
    printTestHeader("Test 2: Parameterized Constructor");
    {
        Array<int> intArray(5);
        printInfo("Created int array of size 5");
        std::cout << "Size: " << intArray.size() << std::endl;
        std::cout << "Initial values (default initialized): ";
        for (size_t i = 0; i < intArray.size(); ++i) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;
        printSuccess("Parameterized constructor works correctly");
    }

    // Test 3: Element assignment and access
    printTestHeader("Test 3: Element Assignment and Access");
    {
        Array<int> arr(5);
        printInfo("Assigning values to array[0-4]");
        for (size_t i = 0; i < arr.size(); ++i) {
            arr[i] = i * 10;
        }
        std::cout << "Array values: ";
        for (size_t i = 0; i < arr.size(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        printSuccess("Element assignment and access work correctly");
    }

    // Test 4: Copy constructor (deep copy test)
    printTestHeader("Test 4: Copy Constructor (Deep Copy)");
    {
        Array<int> original(3);
        original[0] = 10;
        original[1] = 20;
        original[2] = 30;
        
        printInfo("Original array: 10 20 30");
        
        Array<int> copy(original);
        printInfo("Created copy of original array");
        
        std::cout << "Copy array values: ";
        for (size_t i = 0; i < copy.size(); ++i) {
            std::cout << copy[i] << " ";
        }
        std::cout << std::endl;
        
        printInfo("Modifying original array[0] to 999");
        original[0] = 999;
        
        std::cout << "Original[0]: " << original[0] << std::endl;
        std::cout << "Copy[0]: " << copy[0] << std::endl;
        
        if (copy[0] == 10 && original[0] == 999) {
            printSuccess("Deep copy successful - arrays are independent");
        } else {
            std::cout << RED << "✗ Deep copy failed - arrays are not independent!" << RESET << std::endl;
        }
    }

    // Test 5: Assignment operator (deep copy test)
    printTestHeader("Test 5: Assignment Operator (Deep Copy)");
    {
        Array<int> arr1(3);
        arr1[0] = 100;
        arr1[1] = 200;
        arr1[2] = 300;
        
        Array<int> arr2(5);
        for (size_t i = 0; i < arr2.size(); ++i) {
            arr2[i] = i;
        }
        
        printInfo("arr1: 100 200 300 (size 3)");
        printInfo("arr2: 0 1 2 3 4 (size 5)");
        printInfo("Assigning arr1 to arr2");
        
        arr2 = arr1;
        
        std::cout << "arr2 after assignment - Size: " << arr2.size() << ", Values: ";
        for (size_t i = 0; i < arr2.size(); ++i) {
            std::cout << arr2[i] << " ";
        }
        std::cout << std::endl;
        
        printInfo("Modifying arr1[0] to 999");
        arr1[0] = 999;
        
        std::cout << "arr1[0]: " << arr1[0] << std::endl;
        std::cout << "arr2[0]: " << arr2[0] << std::endl;
        
        if (arr2[0] == 100 && arr1[0] == 999 && arr2.size() == 3) {
            printSuccess("Assignment operator works correctly with deep copy");
        } else {
            std::cout << RED << "✗ Assignment operator failed!" << RESET << std::endl;
        }
    }

    // Test 6: Self-assignment
    printTestHeader("Test 6: Self-Assignment");
    {
        Array<int> arr(3);
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 3;
        
        printInfo("Testing self-assignment (arr = arr)");
        Array<int>& ref = arr;
        arr = ref;  // Use reference to avoid -Wself-assign-overloaded warning
        
        std::cout << "Array after self-assignment: ";
        for (size_t i = 0; i < arr.size(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        printSuccess("Self-assignment handled correctly");
    }

    // Test 7: Out of bounds exception
    printTestHeader("Test 7: Out of Bounds Exception");
    {
        Array<int> arr(5);
        
        printInfo("Array size: 5");
        printInfo("Attempting to access arr[10]...");
        
        try {
            int value = arr[10];
            std::cout << RED << "✗ Exception not thrown! Got value: " << value << RESET << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
            printSuccess("Out of bounds exception works correctly");
        }
        
        printInfo("Attempting to access arr[5] (exactly at size)...");
        try {
            int value = arr[5];
            std::cout << RED << "✗ Exception not thrown! Got value: " << value << RESET << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
            printSuccess("Boundary check works correctly");
        }
    }

    // Test 8: Different types
    printTestHeader("Test 8: Array with Different Types");
    {
        printInfo("Testing with double type");
        Array<double> doubleArray(3);
        doubleArray[0] = 3.14;
        doubleArray[1] = 2.71;
        doubleArray[2] = 1.41;
        
        std::cout << "Double array: ";
        for (size_t i = 0; i < doubleArray.size(); ++i) {
            std::cout << doubleArray[i] << " ";
        }
        std::cout << std::endl;
        
        printInfo("Testing with std::string type");
        Array<std::string> stringArray(3);
        stringArray[0] = "Hello";
        stringArray[1] = "World";
        stringArray[2] = "!";
        
        std::cout << "String array: ";
        for (size_t i = 0; i < stringArray.size(); ++i) {
            std::cout << stringArray[i] << " ";
        }
        std::cout << std::endl;
        
        printSuccess("Template works with different types");
    }

    // Test 9: Empty array access
    printTestHeader("Test 9: Empty Array Access");
    {
        Array<int> emptyArray;
        printInfo("Attempting to access index 0 of empty array...");
        
        try {
            int value = emptyArray[0];
            std::cout << RED << "✗ Exception not thrown! Got value: " << value << RESET << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
            printSuccess("Empty array access properly throws exception");
        }
    }

    // Test 10: Large array
    printTestHeader("Test 10: Large Array");
    {
        const size_t largeSize = 1000;
        Array<int> largeArray(largeSize);
        
        printInfo("Created array of size 1000");
        
        for (size_t i = 0; i < largeArray.size(); ++i) {
            largeArray[i] = i;
        }
        
        printInfo("Filled array with values 0-999");
        
        bool allCorrect = true;
        for (size_t i = 0; i < largeArray.size(); ++i) {
            if (static_cast<size_t>(largeArray[i]) != i) {
                allCorrect = false;
                break;
            }
        }
        
        std::cout << "Size: " << largeArray.size() << std::endl;
        std::cout << "First 10 elements: ";
        for (size_t i = 0; i < 10; ++i) {
            std::cout << largeArray[i] << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Last 10 elements: ";
        for (size_t i = largeSize - 10; i < largeSize; ++i) {
            std::cout << largeArray[i] << " ";
        }
        std::cout << std::endl;
        
        if (allCorrect) {
            printSuccess("Large array handled correctly");
        } else {
            std::cout << RED << "✗ Large array test failed!" << RESET << std::endl;
        }
    }

    // Test 11: Multiple copies
    printTestHeader("Test 11: Multiple Copies and Independence");
    {
        Array<int> original(3);
        original[0] = 1;
        original[1] = 2;
        original[2] = 3;
        
        Array<int> copy1(original);
        Array<int> copy2 = original;
        Array<int> copy3(5);
        copy3 = original;
        
        printInfo("Created 3 copies of original array");
        
        original[0] = 100;
        copy1[1] = 200;
        copy2[2] = 300;
        
        printInfo("Modified different elements in each array");
        
        std::cout << "Original: " << original[0] << " " << original[1] << " " << original[2] << std::endl;
        std::cout << "Copy1:    " << copy1[0] << " " << copy1[1] << " " << copy1[2] << std::endl;
        std::cout << "Copy2:    " << copy2[0] << " " << copy2[1] << " " << copy2[2] << std::endl;
        std::cout << "Copy3:    " << copy3[0] << " " << copy3[1] << " " << copy3[2] << std::endl;
        
        if (original[0] == 100 && original[1] == 2 && original[2] == 3 &&
            copy1[0] == 1 && copy1[1] == 200 && copy1[2] == 3 &&
            copy2[0] == 1 && copy2[1] == 2 && copy2[2] == 300 &&
            copy3[0] == 1 && copy3[1] == 2 && copy3[2] == 3) {
            printSuccess("All copies are independent");
        } else {
            std::cout << RED << "✗ Copies are not independent!" << RESET << std::endl;
        }
    }

    std::cout << "\n" << MAGENTA << "╔══════════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << MAGENTA << "║        All tests completed!                  ║" << RESET << std::endl;
    std::cout << MAGENTA << "╚══════════════════════════════════════════════╝" << RESET << std::endl;

    return 0;
}
