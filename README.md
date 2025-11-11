# Dynamic Array Implementation in C++

A comprehensive C++ template-based dynamic array implementation using object-oriented programming with inheritance. This university project demonstrates advanced C++ concepts including templates, inheritance, move semantics, and operator overloading.

## Features

- Generic template-based implementation supporting multiple data types
- Hierarchical class structure with inheritance
- Dynamic memory management with automatic resizing
- Comprehensive array manipulation methods
- File I/O operations for data persistence
- Advanced algorithms (QuickSort, maximum subarray)
- Functional programming support (forEach, map)
- Full test coverage using Google Test framework

## Class Hierarchy

The project uses a hierarchical inheritance structure:

```
ArrayBase
    ↓
ArrayUtils
    ↓
ArraySorting
    ↓
ArrayFileIO
    ↓
ArrayAdvanced
    ↓
ArrayFull (main interface)
```

### Supported Data Types

- `int` - Integer values
- `float` - Single-precision floating-point
- `double` - Double-precision floating-point
- `long` - Long integer values
- `char` - Character values

## Class Descriptions

### ArrayBase
Foundation class providing basic array operations:
- `push()` - Add element to the end
- `unshift()` - Add element to the beginning
- `pop()` - Remove and return last element
- `shift()` - Remove and return first element
- `getElementAt()` - Access element at specific index

### ArrayUtils
Utility methods for array operations:
- `find()` - Find first occurrence of a value
- `findMax()` - Find maximum element
- `findMin()` - Find minimum element
- `reverse()` - Reverse array order
- `removeDuplicates()` - Remove duplicate elements

### ArraySorting
Sorting algorithms:
- `quickSort()` - Sort array using QuickSort algorithm

### ArrayFileIO
File operations:
- `exportToFile()` - Save array to file
- `importFromFile()` - Load array from file

### ArrayAdvanced
Advanced array manipulations:
- `subArray()` - Extract subarray from specified range
- `swap()` - Swap two elements
- `removeByIndex()` - Remove element at specific index
- `intersect()` - Find intersection of two arrays
- `maxSubarray()` - Find maximum sum subarray
- `merge()` - Merge two arrays
- `forEach()` - Apply function to each element
- `map()` - Transform array elements with function

### ArrayFull
Main interface combining all functionality:
- Default, parameterized, and copy/move constructors
- Assignment operators (copy and move)
- Index operator `[]` for element access
- All methods from parent classes
- Enhanced `merge()` and `intersect()` accepting ArrayFull instances

## Building the Project

### Prerequisites

- C++20 compatible compiler
- CMake 3.29 or higher
- Google Test framework (included in project)

### Build Instructions

```bash
# Navigate to project directory
cd ProjectC++

# Create build directory
mkdir build
cd build

# Generate build files
cmake ..

# Build the project
cmake --build .

# Run tests
./Project
```

## Usage Example

```cpp
#include "ArrayFull.h"

int main() {
    // Create an integer array
    ArrayFull<int> arr;

    // Add elements
    arr.push(10);
    arr.push(20);
    arr.push(30);
    arr.unshift(5);  // [5, 10, 20, 30]

    // Access elements
    int first = arr[0];  // 5
    int last = arr.pop();  // 30, array becomes [5, 10, 20]

    // Find operations
    int max = arr.findMax();  // 20
    int min = arr.findMin();  // 5

    // Sort array
    arr.quickSort();

    // Advanced operations
    arr.forEach([](int x) {
        std::cout << x << " ";
    });

    // Save to file
    arr.exportToFile("data.txt");

    // Load from file
    ArrayFull<int> arr2;
    arr2.importFromFile("data.txt");

    return 0;
}
```

## Testing

The project includes comprehensive unit tests using Google Test framework:

- `testArrayBase.cpp` - Tests for basic operations
- `testArrayUtils.cpp` - Tests for utility methods
- `testArraySorting.cpp` - Tests for sorting algorithms
- `testArrayFileIO.cpp` - Tests for file operations
- `testArrayAdvanced.cpp` - Tests for advanced methods
- `testArrayFull.cpp` - Integration tests for ArrayFull class

## Project Structure

```
ProjectC++/
├── ArrayBase.h/cpp          # Base array operations
├── ArrayUtils.h/cpp         # Utility methods
├── ArraySorting.h/cpp       # Sorting algorithms
├── ArrayFileIO.h/cpp        # File I/O operations
├── ArrayAdvanced.h/cpp      # Advanced manipulations
├── ArrayFull.h/cpp          # Main array interface
├── test*.cpp                # Unit tests
├── CMakeLists.txt           # Build configuration
├── googletest/              # Testing framework
└── README.md                # This file
```

## Technical Details

- **Memory Management**: Dynamic allocation with automatic resizing using a growth factor of 2
- **Initial Capacity**: 1 element
- **Exception Safety**: Throws `std::out_of_range` for invalid indices
- **Performance**: O(1) amortized for push/pop, O(n log n) for sorting
- **Thread Safety**: Not thread-safe (single-threaded usage)

## Author

Anastasiia Honcharenko

## License

University project - Educational use only

## Notes

This project was developed as part of a university course to demonstrate understanding of:
- C++ templates and generic programming
- Object-oriented design and inheritance
- Memory management and RAII principles
- STL-style container design
- Unit testing practices