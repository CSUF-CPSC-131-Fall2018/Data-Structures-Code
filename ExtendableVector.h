#pragma once

#include <stdexcept>
#include <algorithm> // needed for std::max in ExtendableVector::insert()
using namespace std;

const int DEFAULT_CAPACITY = 100;

// Declaration
template <typename T>
class ExtendableVector {
private:
    int _capacity;                  // current max capacity
    int _size;                      // number of elements in array
    T* _array;                      // array storing elements

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
    _capacity = DEFAULT_CAPACITY;
    _size = 0;
    _array = new T[_capacity];
}

// Constructor with initial capacity argument
template <typename T>
ExtendableVector<T>::ExtendableVector(int capacity) {
    _capacity = capacity;
    _size = 0;
    _array = new T[_capacity];
}

// Copy Constructor
template <typename T>
ExtendableVector<T>::ExtendableVector(const ExtendableVector& input) {
    _capacity = input._capacity;
    _size = input._size;
    _array = new T[_capacity];
    for (int i = 0; i < _size; i++) {
        _array[i] = input._array[i];
    }
}

// Deconstructor
template <typename T>
ExtendableVector<T>::~ExtendableVector() {
    delete[] _array;
}

// Getter
template <typename T>
T& ExtendableVector<T>::get(int index) {
    if ((index < 0) || (index >= _size)) {
        throw range_error("index out of bounds");
    }
    return _array[index];
}

template <typename T>
void ExtendableVector<T>::insert(int index, T value) {
    if ((index < 0)) {
        throw range_error("index out of bounds");
    }
    // If at max capacity, double the capacity
    if (_size >= _capacity) {
        reserve(max(1, 2 * _capacity));
    }
    // Shift values up
    for (int i = _size - 1; i >= index; i--) {
        _array[i + 1] = _array[i];
    }
    _array[index] = value;
    _size++;
}

template <typename T>
void ExtendableVector<T>::erase(int index) {
    // Shift values down
    for (int i = index + 1; i < _size; i++) {
        _array[i - 1] = _array[i];
    }
    _size--;
}

template <typename T>
int ExtendableVector<T>::getSize() {
    return _size;
}

template <typename T>
int ExtendableVector<T>::getCapacity() {
    return _capacity;
}

template <typename T>
bool ExtendableVector<T>::isEmpty() {
    return (_size == 0);
}

template <typename T>
void ExtendableVector<T>::reserve(int capacity) {
    if (capacity > _capacity) {
        T* new_array = new T[capacity];
        // Copy values to new array
        for (int i = 0; i < _size; i++) {
            new_array[i] = _array[i];
        }
        delete[] _array;
        _array = new_array;
        _capacity = capacity;
    }
}

template <typename T>
ExtendableVector<T>& ExtendableVector<T>::operator=(const ExtendableVector& rhs) {
    if (this != &rhs) {
        delete[] _array;
        _capacity = rhs._capacity;
        _size = rhs._size;
        _array = new T[_capacity];
        for (int i = 0; i < _size; i++) {
            _array[i] = rhs._array[i];
        }
    }
    return *this;
}

template <typename T>
T& ExtendableVector<T>::operator[](int index) {
    return get(index);
}
