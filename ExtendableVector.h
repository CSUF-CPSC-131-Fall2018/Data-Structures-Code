#pragma once

#include <stdexcept>
#include <algorithm> // needed for std::max in ExtendableVector::insert()
using namespace std;

const int DEFAULT_CAPACITY = 100;

// Declaration
template <typename T>
class ExtendableVector {
private:
    int capacity;                   // current max capacity
    int size;                       // number of elements in array
    T* array;                       // array storing elements

public:
    // Constructors
    ExtendableVector();
    ExtendableVector(int);
    ExtendableVector(const ExtendableVector&);
    ~ExtendableVector();

    // Getters / Setters
    T& get(int);
    void insert(int, T);
    void erase(int);
    int getSize();
    int getCapacity();
    bool isEmpty();

    // Helpers
    void reserve(int);

    // Overloaded Operators
    ExtendableVector& operator=(const ExtendableVector&);
    T& operator[](int);
};


// Implementation
// Default Constructor
template <typename T>
ExtendableVector<T>::ExtendableVector() {
    capacity = DEFAULT_CAPACITY;
    size = 0;
    array = new T[capacity];
}

// Constructor with initial capacity argument
template <typename T>
ExtendableVector<T>::ExtendableVector(int newCapacity) {
    capacity = newCapacity;
    size = 0;
    array = new T[capacity];
}

// Copy Constructor
template <typename T>
ExtendableVector<T>::ExtendableVector(const ExtendableVector& input) {
    capacity = input.capacity;
    size = input.size;
    array = new T[capacity];
    for (int i = 0; i < size; i++) {
        array[i] = input.array[i];
    }
}

// Deconstructor
template <typename T>
ExtendableVector<T>::~ExtendableVector() {
    delete[] array;
}

// Getter
template <typename T>
T& ExtendableVector<T>::get(int index) {
    if ((index < 0) || (index >= size)) {
        throw range_error("index out of bounds");
    }
    return array[index];
}

template <typename T>
void ExtendableVector<T>::insert(int index, T value) {
    if ((index < 0)) {
        throw range_error("index out of bounds");
    }
    // If at max capacity, double the capacity
    if (size >= capacity) {
        reserve(max(1, 2 * capacity));
    }
    // Shift values up
    for (int i = size - 1; i >= index; i--) {
        array[i + 1] = array[i];
    }
    array[index] = value;
    size++;
}

template <typename T>
void ExtendableVector<T>::erase(int index) {
    // Shift values down
    for (int i = index + 1; i < size; i++) {
        array[i - 1] = array[i];
    }
    size--;
}

template <typename T>
int ExtendableVector<T>::getSize() {
    return size;
}

template <typename T>
int ExtendableVector<T>::getCapacity() {
    return capacity;
}

template <typename T>
bool ExtendableVector<T>::isEmpty() {
    return (size == 0);
}

template <typename T>
void ExtendableVector<T>::reserve(int newCapacity) {
    if (newCapacity > capacity) {
        T* newArray = new T[newCapacity];
        // Copy values to new array
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }
}

template <typename T>
ExtendableVector<T>& ExtendableVector<T>::operator=(const ExtendableVector& rhs) {
    if (this != &rhs) {
        delete[] array;
        capacity = rhs.capacity;
        size = rhs.size;
        array = new T[capacity];
        for (int i = 0; i < size; i++) {
            array[i] = rhs.array[i];
        }
    }
    return *this;
}

template <typename T>
T& ExtendableVector<T>::operator[](int index) {
    return get(index);
}
