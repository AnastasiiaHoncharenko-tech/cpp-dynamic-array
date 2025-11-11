#ifndef ARRAYSORTING_H
#define ARRAYSORTING_H

#include "ArrayUtils.h"
#include <algorithm>
using std::swap;

template <typename T>
class ArraySorting : public ArrayUtils<T> {
protected:
    ArraySorting();

    ArraySorting(const ArraySorting<T>&) = delete;
    ArraySorting<T>& operator=(const ArraySorting<T>&) = delete;

    static void quickSort(T* array, int size);

private:
    static void quickSortHelper(T* array, int low, int high);
    static int partition(T* array, int low, int high);
};

#endif // ARRAYSORTING_H
