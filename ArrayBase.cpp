#include "ArrayBase.h"

template <typename T>
ArrayBase<T>::ArrayBase() {}

template <typename T>
void ArrayBase<T>::resize(T*& array, int& size, int& capacity) {
    if (!capacity) {
        capacity = INITIAL_CAPACITY;
    } else {
        capacity *= GROWTH_FACTOR;
    }

    T* newArray = new T[capacity];
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }

    delete[] array;
    array = newArray;
}

template <typename T>
void ArrayBase<T>::push(T*& array, int& size, int& capacity, const T& value) {
    if (size == capacity) {
        resize(array, size, capacity);
    }
    if (!size) {
        array = new T[capacity];
    }
    array[size] = value;
    size++;
}

template <typename T>
void ArrayBase<T>::unshift(T*& array, int& size, int& capacity, const T& value) {
    if (size == capacity) {
        resize(array, size, capacity);
    }
    if (!size) {
        array = new T[capacity];
    } else {
        for (int i = size; i > 0; i--) {
            array[i] = array[i - 1];
        }
    }

    size++;
    array[FIRST_ITEM_INDEX] = value;
}

template <typename T>
T ArrayBase<T>::pop(T*& array, int& size) {
    if (!size) {
        throw std::underflow_error("Pop is impossible, array is empty");
    }

    T value = array[size - 1];
    size--;
    return value;
}

template <typename T>
T ArrayBase<T>::shift(T*& array, int& size) {
    if (!size) {
        throw std::underflow_error("Shift is impossible, array is empty");
    }

    T value = array[FIRST_ITEM_INDEX];
    for (int i = 0; i < size - 1; i++) {
        array[i] = array[i + 1];
    }

    size--;
    return value;
}

template <typename T>
T ArrayBase<T>::getElementAt(const T* array, int& size, int index) {
    if (index < MINIMAL_ARRAY_INDEX || index >= size) {
        throw std::out_of_range("Index is out of range");
    }

    return array[index];
}

template class ArrayBase<int>;
template class ArrayBase<double>;
template class ArrayBase<char>;
template class ArrayBase<float>;
template class ArrayBase<long>;