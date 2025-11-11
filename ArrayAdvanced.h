#ifndef ARRAYADVANCED_H
#define ARRAYADVANCED_H

#include "ArrayFileIO.h"

template <typename T>
class ArrayAdvanced : public ArrayFileIO<T> {
protected:
    ArrayAdvanced();

    ArrayAdvanced(const ArrayAdvanced<T>&) = delete;
    ArrayAdvanced<T>& operator=(const ArrayAdvanced<T>&) = delete;

    static T* subArray(const T* array, int size, int start, int end);
    static void swap(T* array, int size, int firstElement, int secondElement);
    static void removeByIndex(T*& array, int& size, int index);
    static T* intersect(const T* array1, int size1, const T* array2, int size2);
    static T* maxSubarray(const T* array, int size);
    static T* merge(const T* array1, int size1, const T* array2, int size2);
    static void forEach(T* array, int size, std::function<void(T)> func);
    static T* map(const T* array, int size, std::function<T(T)> func);
};

const int MINIMAL_SUM = 0;

#endif // ARRAYADVANCED_H
