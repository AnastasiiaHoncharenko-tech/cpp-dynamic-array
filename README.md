# Dynamic Array Implementation

C++ template-based dynamic array for university project.

## Overview

This project implements a dynamic array data structure using class inheritance in C++. The array supports multiple data types through templates.

## Class Structure

```
ArrayBase -> ArrayUtils -> ArraySorting -> ArrayFileIO -> ArrayAdvanced -> ArrayFull
```

Create array objects using the `ArrayFull` class.

Supported types: `int`, `float`, `double`, `long`, `char`

## Features

**ArrayBase** - basic operations
- push, pop, shift, unshift, getElementAt

**ArrayUtils** - utilities
- find, findMax, findMin, reverse, removeDuplicates

**ArraySorting**
- quickSort

**ArrayFileIO**
- exportToFile, importFromFile

**ArrayAdvanced**
- subArray, swap, removeByIndex, intersect, maxSubarray, merge, forEach, map

**ArrayFull** - main class with all functionality plus constructors and operators

## Building

```bash
mkdir build && cd build
cmake ..
cmake --build .
./Project
```

## Requirements

- C++20
- CMake 3.29+
- GoogleTest (included)

## Example

```cpp
ArrayFull<int> arr;
arr.push(10);
arr.push(20);
arr.quickSort();
arr.exportToFile("data.txt");
```

## Testing

All classes have unit tests using GoogleTest framework.

## Author

Anastasiia Honcharenko
