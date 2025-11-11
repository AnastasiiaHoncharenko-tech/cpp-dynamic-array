#ifndef ARRAYFILEIO_H
#define ARRAYFILEIO_H

#include "ArraySorting.h"
#include <string>
#include <fstream>

template <typename T>
class ArrayFileIO : public ArraySorting<T> {
protected:
    ArrayFileIO();

    ArrayFileIO(const ArrayFileIO<T>&) = delete;
    ArrayFileIO<T>& operator=(const ArrayFileIO<T>&) = delete;

    static void exportToFile(const T* array, int size, const std::string& filename);
    static T* importFromFile(T*& array, int& size, const std::string& filename);
};

const int EMPTY_ARRAY_SIZE = 0;

#endif // ARRAYFILEIO_H
