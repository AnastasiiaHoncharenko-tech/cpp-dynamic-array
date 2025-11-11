#ifndef ARRAY_BASE_H
#define ARRAY_BASE_H

#include <stdexcept>

template <typename T>
class ArrayBase {
protected:
    ArrayBase();

    ArrayBase(const ArrayBase<T>&) = delete;
    ArrayBase<T>& operator=(const ArrayBase<T>&) = delete;

    static void push(T*& array, int& size, int& capacity, const T& value);
    static void unshift(T*& array, int& size, int& capacity, const T& value);
    static T pop(T*& array, int& size);
    static T shift(T*& array, int& size);
    static T getElementAt(const T* array, int& size, int index);
private:
    static void resize(T*& array, int& size, int& capacity);
};

const int INITIAL_CAPACITY = 1;
const int GROWTH_FACTOR = 2;
const int FIRST_ITEM_INDEX = 0;
const int MINIMAL_ARRAY_INDEX = 0;

#endif // ARRAY_BASE_H

