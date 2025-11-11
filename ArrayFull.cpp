#include "ArrayFull.h"

template <typename T>
ArrayFull<T>::ArrayFull() : array(nullptr), size(0), capacity(0) {}

template <typename T>
ArrayFull<T>::ArrayFull(int size) : array(nullptr), size(0), capacity(size) {}

template <typename T>
ArrayFull<T>::ArrayFull(int size, const T& value) : size(size), capacity(size) {
    if (size) {
        array = new T[capacity];

        for (int i = 0; i < size; i++) {
            array[i] = value;
        }
    } else {
        array = nullptr;
    }
}

template <typename T>
ArrayFull<T>::ArrayFull(T* arr, int size) {
    this->size = size;
    this->capacity = size;
    if (size) {
        array = new T[capacity];

        for (int i = 0; i < size; i++) {
            array[i] = arr[i];
        }
    } else {
        array = nullptr;
    }
}

template <typename T>
ArrayFull<T>::ArrayFull(const ArrayFull<T>& other) : size(other.size), capacity(other.capacity) {
    if (size) {
        array = new T[capacity];

        for (int i = 0; i < size; i++) {
            array[i] = other.array[i];
        }
    } else {
        array = nullptr;
    }
}

template <typename T>
ArrayFull<T>::ArrayFull(ArrayFull<T>&& other) : array(other.array), size(other.size), capacity(other.capacity) {
    other.array = nullptr;
    other.size = INITIAL_SIZE;
    other.capacity = INITIAL_SIZE;
}

template <typename T>
ArrayFull<T>& ArrayFull<T>::operator=(const ArrayFull<T>& other) {
    if (this != &other) {
        delete[] array;

        size = other.size;
        capacity = other.capacity;
        if (size) {
            array = new T[capacity];

            for (int i = 0; i < size; ++i) {
                array[i] = other.array[i];
            }
        } else {
            array = nullptr;
        }
    }
    return *this;
}

template <typename T>
ArrayFull<T>& ArrayFull<T>::operator=(ArrayFull<T>&& other) {
    if (this != &other) {
        delete[] array;

        array = other.array;
        size = other.size;
        capacity = other.capacity;

        other.array = nullptr;
        other.size = INITIAL_SIZE;
        other.capacity = INITIAL_SIZE;
    }
    return *this;
}

template <typename T>
ArrayFull<T>::~ArrayFull() {
    delete[] array;
}

template <typename T>
T& ArrayFull<T>::operator[](int index) {
    if (index < MINIMAL_ARRAY_INDEX || index >= size) {
        throw std::out_of_range("Index is out of range");
    }
    return array[index];
}

template <typename T>
int ArrayFull<T>::getSize() const {
    return size;
}

template <typename T>
int ArrayFull<T>::getCapacity() const {
    return capacity;
}

template <typename T>
void ArrayFull<T>::print() const {
    for (int i = 0; i < size - 1; i++) {
        std::cout << array[i] << SEPARATOR;
    }

    std::cout << array[size - 1];
    std::cout << std::endl;
}

template <typename T>
void ArrayFull<T>::push(const T& value) {
    ArrayBase<T>::push(array, size, capacity, value);
}

template <typename T>
void ArrayFull<T>::unshift(const T& value) {
    ArrayBase<T>::unshift(array, size, capacity, value);
}

template <typename T>
T ArrayFull<T>::pop() {
    return ArrayBase<T>::pop(array, size);
}

template <typename T>
T ArrayFull<T>::shift() {
    return ArrayBase<T>::shift(array, size);
}

template <typename T>
T ArrayFull<T>::getElementAt(const int index) {
    return ArrayBase<T>::getElementAt(array, size, index);
}

template <typename T>
T ArrayFull<T>::find(const T& value) {
    return ArrayUtils<T>::find(array, size, value);
}

template <typename T>
T ArrayFull<T>::findMax() {
    return ArrayUtils<T>::findMax(array, size);
}

template <typename T>
T ArrayFull<T>::findMin() {
    return ArrayUtils<T>::findMin(array, size);
}

template <typename T>
void ArrayFull<T>::reverse() {
    ArrayUtils<T>::reverse(array, size);
}

template <typename T>
void ArrayFull<T>::removeDuplicates() {
    ArrayUtils<T>::removeDuplicates(array, size, capacity);
}

template <typename T>
void ArrayFull<T>::quickSort() {
    ArraySorting<T>::quickSort(array, size);
}

template <typename T>
void ArrayFull<T>::exportToFile(const std::string& filename) {
    ArrayFileIO<T>::exportToFile(array, size, filename);
}

template <typename T>
T* ArrayFull<T>::importFromFile(const std::string& filename) {
    return ArrayFileIO<T>::importFromFile(array, size, filename);
}

template <typename T>
void ArrayFull<T>::merge(const T* other, int otherSize){
    array = ArrayAdvanced<T>::merge(array, size, other, otherSize);
    size += otherSize;
};

template <typename T>
void ArrayFull<T>::merge(ArrayFull<T> other, int otherSize){
    int newSize = size + otherSize;
    T* newArray = new T[newSize];

    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    for (int i = 0; i < otherSize; i++) {
        newArray[size + i] = other[i];
    }
    array = newArray;
    size = newSize;
};

template <typename T>
void ArrayFull<T>::forEach(std::function<void(T)> func){
    ArrayAdvanced<T>::forEach(array, size, func);
};

template <typename T>
T* ArrayFull<T>::map(std::function<T(T)> func){
   return ArrayAdvanced<T>::map(array, size, func);
};

template <typename T>
T* ArrayFull<T>::subArray(int start, int end){
   return ArrayAdvanced<T>::subArray(array, size, start, end);
};

template <typename T>
void ArrayFull<T>::swap(int firstElement, int secondElement){
    ArrayAdvanced<T>::swap(array, size, firstElement, secondElement);
};

template <typename T>
void ArrayFull<T>::removeByIndex(int index){
    ArrayAdvanced<T>::removeByIndex(array, size, index);
};

template <typename T>
T* ArrayFull<T>::intersect(const T* other, int otherSize){
    return ArrayAdvanced<T>::intersect(array, size, other, otherSize);
};

template <typename T>
T* ArrayFull<T>::intersect(ArrayFull<T> other, int otherSize){

    int currentIndex = 0;
    int newSize = size < otherSize ? size : otherSize;
    T* tempArray = new T[newSize];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < otherSize; j++) {
            if (array[i] == other[j]) {
                tempArray[currentIndex] = array[i];
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
};

template <typename T>
T* ArrayFull<T>::maxSubarray(){
    return ArrayAdvanced<T>::maxSubarray(array, size);
};

template class ArrayFull<int>;
template class ArrayFull<double>;
template class ArrayFull<char>;
template class ArrayFull<float>;
template class ArrayFull<long>;