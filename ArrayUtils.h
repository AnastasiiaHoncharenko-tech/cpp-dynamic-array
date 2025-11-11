#ifndef ARRAYUTILS_H
#define ARRAYUTILS_H

#include "ArrayBase.h"
#include <stdexcept>

template <typename T>
class ArrayUtils : public ArrayBase<T> {
protected:
    ArrayUtils();

    ArrayUtils(const ArrayUtils<T>&) = delete;
    ArrayUtils<T>& operator=(const ArrayUtils<T>&) = delete;

    static T find(const T* array, int size, const T& value);
    static T findMax(const T* array, int size);
    static T findMin(const T* array, int size);
    static void reverse(T* array, int size);
    static void removeDuplicates(T*& array, int& size, int& capacity);
};

const int NOT_FOUNDED_VALUE = -1;

#endif // ARRAYUTILS_H
