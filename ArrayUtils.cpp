#include "ArrayUtils.h"

template <typename T>
ArrayUtils<T>::ArrayUtils() {}

template <typename T>
T ArrayUtils<T>::find(const T* array, int size, const T& value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return i;
        }
    }

    return NOT_FOUNDED_VALUE;
}

template <typename T>
T ArrayUtils<T>::findMax(const T* array, int size) {
    if (!size) {
        throw std::underflow_error("Finding of maximum is impossible, array is empty");
    }

    T maxValue = array[FIRST_ITEM_INDEX];
    for (int i = 1; i < size; i++) {
        if (array[i] > maxValue) {
            maxValue = array[i];
        }
    }

    return maxValue;
}

template <typename T>
T ArrayUtils<T>::findMin(const T* array, int size) {
    if (!size) {
        throw std::underflow_error("Finding of minimum is impossible, array is empty");
    }

    T minValue = array[FIRST_ITEM_INDEX];
    for (int i = 1; i < size; i++) {
        if (array[i] < minValue) {
            minValue = array[i];
        }
    }

    return minValue;
}

template <typename T>
void ArrayUtils<T>::reverse(T* array, int size) {
    int start = FIRST_ITEM_INDEX;
    int end = size - 1;

    while (start < end) {
        T temp = array[start];
        array[start] = array[end];
        array[end] = temp;

        start++;
        end--;
    }
}

template <typename T>
void ArrayUtils<T>::removeDuplicates(T*& array, int& size, int& capacity) {
    if (!size) {
        return;
    }

    int count = 0;
    for (int i = 0; i < size; i++) {
        bool check = false;

        for (int j = 0; j < count; j++) {
            if (array[i] == array[j]) {
                check = true;
                break;
            }
        }

        if (!check) {
            array[count] = array[i];
            count++;
        }
    }

    size = count;
}

template class ArrayUtils<int>;
template class ArrayUtils<double>;
template class ArrayUtils<char>;
template class ArrayUtils<float>;
template class ArrayUtils<long>;

