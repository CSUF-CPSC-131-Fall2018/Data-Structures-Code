#pragma once

#include <stdexcept>
using namespace std;


// Declaration
template <typename T>
class FixedVector {
private:
    int _size;
    T* _array;

public:
    // Constructors
    FixedVector();
    FixedVector(int);
    FixedVector(const FixedVector&);
    ~FixedVector();

    // Getters / Setters
    T& get(int);
    void set(int, T);
    int getSize();
    bool isEmpty();

    // Overloaded Operators
    FixedVector& operator=(const FixedVector&);
    T& operator[](int);
};


// Implementation
// Default Constructor: empty vector
template <typename T>
FixedVector<T>::FixedVector() {
    _size = 0;
    _array = new T[_size];
}

// Constructor with initial size argument
template <typename T>
FixedVector<T>::FixedVector(int size) {
    if (size < 0) {
        throw invalid_argument("size is less than 0");
    }
    _size = size;
    _array = new T[_size];
}

// Copy Constructor
template <typename T>
FixedVector<T>::FixedVector(const FixedVector<T>& input) {
    _size = input._size;
    _array = new T[_size];
    for (int i = 0; i < _size; i++) {
        _array[i] = input._array[i];
    }
}

// Deconstructor
template <typename T>
FixedVector<T>::~FixedVector() {
    delete[] _array;
}

// Getter
template <typename T>
T& FixedVector<T>::get(int index) {
    if ((index < 0) || (index >= _size)) {
        throw range_error("index out of bounds");
    }
    return _array[index];
}

// Setter
template <typename T>
void FixedVector<T>::set(int index, T value) {
    if (isEmpty()) {
        throw invalid_argument("array is empty");
    }
    if ((index < 0) || (index >= _size)) {
        throw range_error("index out of bounds");
    }
    _array[index] = value;
}

template <typename T>
int FixedVector<T>::getSize() {
    return _size;
}

template <typename T>
bool FixedVector<T>::isEmpty() {
    return (_size == 0);
}

// Overloaded Assignment Operator
template <typename T>
FixedVector<T>& FixedVector<T>::operator=(const FixedVector<T>& rhs) {
    if (this != &rhs) {
        delete[] _array;
        _size = rhs._size;
        _array = new T[_size];
        for (int i = 0; i < _size; i++) {
            _array[i] = rhs._array[i];
        }
    }
    return *this;
}

// Overloaded Array-Access Operator
template <typename T>
T& FixedVector<T>::operator[](int index) {
    return get(index);
}
