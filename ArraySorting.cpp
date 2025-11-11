#include "ArraySorting.h"

template <typename T>
ArraySorting<T>::ArraySorting() {}

template <typename T>
void ArraySorting<T>::quickSort(T* array, int size) {
    if (size > INITIAL_CAPACITY) {
        quickSortHelper(array, FIRST_ITEM_INDEX, size - 1);
    }
}

template <typename T>
void ArraySorting<T>::quickSortHelper(T* array, int low, int high) {
    if (low < high) {
        int index = partition(array, low, high);

        quickSortHelper(array, low, index - 1);
        quickSortHelper(array, index + 1, high);
    }
}

template <typename T>
int ArraySorting<T>::partition(T* array, int low, int high) {
    T pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            std::swap(array[i], array[j]);
        }
    }

    std::swap(array[i + 1], array[high]);
    return i + 1;
}

template class ArraySorting<int>;
template class ArraySorting<double>;
template class ArraySorting<char>;
template class ArraySorting<float>;
template class ArraySorting<long>;