#include "ArrayFileIO.h"
#include <stdexcept>

template <typename T>
ArrayFileIO<T>::ArrayFileIO() {}

template <typename T>
void ArrayFileIO<T>::exportToFile(const T* array, int size, const std::string& fileName) {
    std::ofstream oFile(fileName);

    if (!oFile.is_open()) {
        throw std::runtime_error("Failed to open file for writing: " + fileName);
    }

    for (int i = 0; i < size; i++) {
        oFile << array[i] << " ";
    }

    oFile.close();
}

template <typename T>
T* ArrayFileIO<T>::importFromFile(T*& array, int& size, const std::string& fileName) {
    std::ifstream iFile(fileName);

    if (!iFile.is_open()) {
        throw std::runtime_error("Failed to open file for reading: " + fileName);
    }

    T* tempArray = nullptr;
    T value;
    size = 0;

    while (iFile >> value) {
        T* newArray = new T[size + 1];

        for (int i = 0; i < size; i++) {
            if (tempArray != nullptr) {
                newArray[i] = tempArray[i];
            }
        }
        newArray[size] = value;
        size++;
        delete[] tempArray;
        tempArray = newArray;
    }

    iFile.close();
    array = tempArray;
    return array;
}

template class ArrayFileIO<int>;
template class ArrayFileIO<double>;
template class ArrayFileIO<char>;
template class ArrayFileIO<float>;
template class ArrayFileIO<long>;
