#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
    private:
        T *_data;
        size_t _length;
    public:
        Array();
        Array(size_t n);
        Array(const Array &other);
        Array &operator=(const Array &other);
        ~Array();

        size_t size() const;
        T &operator[](size_t index);

        class OutOfBoundsException : public std::exception {
            public:
                const char* what() const throw();
        };
};

template <typename T>
Array<T>::Array() : _data(NULL), _length(0) {
    std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(size_t n) : _data(new T[n]()), _length(n) {
    std::cout << "Parameterized constructor called for size " << n << std::endl;
}

template <typename T>
Array<T>::Array(const Array &other) : _data(new T[other._length]()), _length(other._length) {
    std::cout << "Copy constructor called" << std::endl;
    for (size_t i = 0; i < _length; ++i) {
        _data[i] = other._data[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    if (this != &other) {
        delete[] _data;
        _length = other._length;
        _data = new T[_length]();
        for (size_t i = 0; i < _length; ++i) {
            _data[i] = other._data[i];
        }
        std::cout << "Copy assignment operator called" << std::endl;
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] _data;
    std::cout << "Destructor called" << std::endl;
}

template <typename T>
size_t Array<T>::size() const {
    return _length;
}

template <typename T>
T &Array<T>::operator[](size_t index) {
    if (index >= _length) {
        throw OutOfBoundsException();
    }
    return _data[index];
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
    return "Array index out of bounds";
}

#endif