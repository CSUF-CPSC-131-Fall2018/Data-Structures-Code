#pragma once

#include <stdexcept>
using namespace std;


// Declaration
template <typename T>
class FixedVector {
private:
    int size;
    T* array;

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
    size = 0;
    array = new T[size];
}

// Constructor with initial size argument
template <typename T>
FixedVector<T>::FixedVector(int newSize) {
    if (newSize < 0) {
        throw invalid_argument("size is less than 0");
    }
    size = newSize;
    array = new T[size];
}

// Copy Constructor
template <typename T>
FixedVector<T>::FixedVector(const FixedVector<T>& input) {
    size = input.size;
    array = new T[size];
    for (int i = 0; i < size; i++) {
        array[i] = input.array[i];
    }
}

// Deconstructor
template <typename T>
FixedVector<T>::~FixedVector() {
    delete[] array;
}

// Getter
template <typename T>
T& FixedVector<T>::get(int index) {
    if ((index < 0) || (index >= size)) {
        throw range_error("index out of bounds");
    }
    return array[index];
}

// Setter
template <typename T>
void FixedVector<T>::set(int index, T value) {
    if (isEmpty()) {
        throw invalid_argument("array is empty");
    }
    if ((index < 0) || (index >= size)) {
        throw range_error("index out of bounds");
    }
    array[index] = value;
}

template <typename T>
int FixedVector<T>::getSize() {
    return size;
}

template <typename T>
bool FixedVector<T>::isEmpty() {
    return (size == 0);
}

// Overloaded Assignment Operator
template <typename T>
FixedVector<T>& FixedVector<T>::operator=(const FixedVector<T>& rhs) {
    if (this != &rhs) {
        delete[] array;
        size = rhs.size;
        array = new T[size];
        for (int i = 0; i < size; i++) {
            array[i] = rhs.array[i];
        }
    }
    return *this;
}

// Overloaded Array-Access Operator
template <typename T>
T& FixedVector<T>::operator[](int index) {
    return get(index);
}
