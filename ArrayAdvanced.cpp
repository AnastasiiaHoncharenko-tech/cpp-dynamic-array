#include "ArrayAdvanced.h"

template <typename T>
ArrayAdvanced<T>::ArrayAdvanced() {}

template <typename T>
T* ArrayAdvanced<T>::subArray(const T* array, int size, int start, int end) {
    if (start < MINIMAL_ARRAY_INDEX ||
        end >= size ||
        start > end ||
        start >= size ||
        end < MINIMAL_ARRAY_INDEX) {
        throw std::out_of_range("Wrong subarray interval");
    }

    int newSize = end - start + 1;
    T* newArray = new T[newSize];

    for (int i = 0; i < newSize; i++) {
        newArray[i] = array[start + i];
    }

    return newArray;
}

template <typename T>
void ArrayAdvanced<T>::swap(T* array, int size, int firstElement, int secondElement) {
    if (firstElement < MINIMAL_ARRAY_INDEX ||
        secondElement < MINIMAL_ARRAY_INDEX ||
        firstElement >= size ||
        secondElement >= size) {
        throw std::out_of_range("Wrong index interval");
    }

    T temp = array[firstElement];
    array[firstElement] = array[secondElement];
    array[secondElement] = temp;
}

template <typename T>
void ArrayAdvanced<T>::removeByIndex(T*& array, int& size, int index) {
    if (index < MINIMAL_ARRAY_INDEX || index >= size) {
        throw std::out_of_range("Wrong index interval");
    }

    T* newArray = new T[size - 1];
    int j = FIRST_ITEM_INDEX;

    for (int i = 0; i < index; i++) {
        newArray[j] = array[i];
        j++;
    }

    for (int i = index + 1; i < size; i++) {
        newArray[j] = array[i];
        j++;
    }

    size--;
    delete[] array;
    array = newArray;
}

template <typename T>
T* ArrayAdvanced<T>::intersect(const T* array1, int size1, const T* array2, int size2) {
    int currentIndex = FIRST_ITEM_INDEX;
    int newSize = size1 < size2 ? size1 : size2;
    T* tempArray = new T[newSize];

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (array1[i] == array2[j]) {
                tempArray[currentIndex] = array1[i];
                currentIndex++;
                break;
            }
        }
    }

    if (!currentIndex) {
        delete [] tempArray;
        return nullptr;
    }

    T* newArray = new T[currentIndex];
    for (int i = 0; i < currentIndex; i++) {
        newArray[i] = tempArray[i];
    }
    return newArray;

}

template <typename T>
T* ArrayAdvanced<T>::maxSubarray(const T* array, int size) {
    if (size <= MINIMAL_ARRAY_INDEX) return nullptr;

    if (std::is_same<T, char>::value) {
        T* result = new T[size];
        for (int i = 0; i < size; ++i) {
            result[i] = array[i];
        }
        return result;
    }

    int start = FIRST_ITEM_INDEX;
    int end = FIRST_ITEM_INDEX;
    int temp = FIRST_ITEM_INDEX;
    T maxSum = array[FIRST_ITEM_INDEX];
    T currentSum = array[FIRST_ITEM_INDEX];

    for (int i = 1; i < size; i++) {
        if (currentSum < MINIMAL_SUM) {
            currentSum = array[i];
            temp = i;
        } else {
            currentSum += array[i];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = temp;
            end = i;
        }
    }

    int newSize = end - start + 1;
    T* result = new T[newSize];

    for (int i = start; i <= end; i++) {
        result[i - start] = array[i];
    }

    return result;
}

template <typename T>
T* ArrayAdvanced<T>::merge(const T* array1, int size1, const T* array2, int size2) {
    int newSize = size1 + size2;
    T* newArray = new T[newSize];

    for (int i = 0; i < size1; i++) {
        newArray[i] = array1[i];
    }
    for (int i = 0; i < size2; i++) {
        newArray[size1 + i] = array2[i];
    }

    return newArray;
}

template <typename T>
void ArrayAdvanced<T>::forEach(T* array, int size, std::function<void(T)> func) {
    for (int i = 0; i < size; i++) {
        func(array[i]);
    }
}

template <typename T>
T* ArrayAdvanced<T>::map(const T* array, int size, std::function<T(T)> func) {
    if (!size) {
        return nullptr;
    }

    T* newArray = new T[size];

    for (int i = 0; i < size; i++) {
        newArray[i] = func(array[i]);
    }

    return newArray;
}

template class ArrayAdvanced<int>;
template class ArrayAdvanced<double>;
template class ArrayAdvanced<char>;
template class ArrayAdvanced<float>;
template class ArrayAdvanced<long>;