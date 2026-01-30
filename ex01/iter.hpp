#ifndef ITER_HPP
#define ITER_HPP

#include <stdlib.h>

// For non-const arrays with non-const functions
template <typename T>
void iter(T* array, const size_t length, void (*func)(T&)) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

// For non-const arrays with const functions
template <typename T>
void iter(T* array, const size_t length, void (*func)(const T&)) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

// For const arrays with const functions
template <typename T>
void iter(const T* array, const size_t length, void (*func)(const T&)) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

#endif