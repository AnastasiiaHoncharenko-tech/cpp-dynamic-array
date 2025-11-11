#ifndef ARRAY_FULL_H
#define ARRAY_FULL_H

#include "ArrayAdvanced.h"
#include "ArrayFileIO.h"
#include <functional>
#include <fstream>
#include <algorithm>
#include <iostream>

#pragma once

template <typename T>
class ArrayFull : public ArrayAdvanced<T> {
private:
    T* array;
    int size;
    int capacity;

public:
    ArrayFull();

    ArrayFull(int size);
    ArrayFull(int size, const T& value);
    ArrayFull(T* arr, int size);

    ArrayFull(const ArrayFull<T>& other);
    ArrayFull(ArrayFull<T>&& other);

    ArrayFull& operator=(const ArrayFull<T>& other);
    ArrayFull& operator=(ArrayFull<T>&& other);

    ~ArrayFull();

    T& operator[](int index);
    int getSize() const;
    int getCapacity() const;
    void print() const;

    void push(const T& value);
    void unshift(const T& value);
    T pop();
    T shift();
    T getElementAt(const int index);

    T find(const T& value);
    T findMax();
    T findMin();
    void reverse();
    void removeDuplicates();

    void quickSort();

    void exportToFile(const std::string& filename);
    T* importFromFile(const std::string& filename);

    void merge(const T* other, int otherSize);
    void merge(ArrayFull<T> other, int otherSize);
    void forEach(std::function<void(T)> func);
    T* map(std::function<T(T)> func);
    T* subArray(int start, int end);
    void swap(int firstElement, int secondElement);
    void removeByIndex(int index);
    T* intersect(const T* other, int otherSize);
    T* intersect(ArrayFull<T> other, int otherSize);
    T* maxSubarray();
};

const int INITIAL_SIZE = 0;
const char SEPARATOR = ' ';

#endif // ARRAY_FULL_H
