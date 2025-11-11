#include "gtest/gtest.h"
#include "ArrayFull.h"
#include <fstream>
#include <sstream>

using namespace ::testing;

// exportToFile
TEST(ArrayFullExportTest, ExportEmptyArray) {
    ArrayFull<int> array;
    array.exportToFile("test_empty_array.txt");

    std::ifstream inputFile("test_empty_array.txt");
    std::stringstream s;
    std::string line;

    while (std::getline(inputFile, line)) {
        s << line;
    }

    std::string fileContent = s.str();

    EXPECT_EQ(fileContent, "");
    inputFile.close();
}

TEST(ArrayFullExportTest, ExportArrayWithData) {
    ArrayFull<int> array;
    array.push(1);
    array.push(2);
    array.push(3);
    array.push(4);
    array.push(5);
    array.exportToFile("test_array.txt");

    std::ifstream inputFile("test_array.txt");
    std::stringstream s;
    std::string line;

    while (std::getline(inputFile, line)) {
        s << line;
    }

    std::string fileContent = s.str();
    std::string expectedContent = "1 2 3 4 5 ";

    EXPECT_EQ(fileContent, expectedContent);
    inputFile.close();
}

TEST(ArrayFullExportTest, ExportArrayWithFloatData) {
    ArrayFull<float> array;
    array.push(1.1f);
    array.push(2.2f);
    array.push(3.3f);
    array.exportToFile("test_float_array.txt");

    std::ifstream inputFile("test_float_array.txt");
    std::stringstream s;
    std::string line;

    while (std::getline(inputFile, line)) {
        s << line;
    }

    std::string fileContent = s.str();
    std::string expectedContent = "1.1 2.2 3.3 ";

    EXPECT_EQ(fileContent, expectedContent);
    inputFile.close();
}

TEST(ArrayFullExportTest, ExportArrayWithCharData) {
    ArrayFull<char> array;
    array.push('a');
    array.push('b');
    array.exportToFile("test_char_array.txt");

    std::ifstream inputFile("test_char_array.txt");
    std::stringstream s;
    char value;

    while (inputFile.get(value)) {
        s << value;
    }

    std::string fileContent = s.str();
    std::string expectedContent = "a b ";

    EXPECT_EQ(fileContent, expectedContent);
    inputFile.close();
}

TEST(ArrayFullExportTest, ExportToWrongFile) {
    ArrayFull<int> array;
    EXPECT_THROW(array.exportToFile(""), std::runtime_error);
}

// importFromFile
TEST(ArrayFullImportTest, ImportEmptyArray) {
    ArrayFull<int> array;
    array.exportToFile("test_empty_array.txt");

    ArrayFull<int> importedArray;
    importedArray.importFromFile("test_empty_array.txt");

    EXPECT_EQ(importedArray.getSize(), 0);
}

TEST(ArrayFullImportTest, ImportArrayWithData) {
    ArrayFull<int> array;
    array.push(10);
    array.push(20);
    array.push(30);
    array.push(40);
    array.push(50);
    array.exportToFile("test_array.txt");

    ArrayFull<int> importedArray;
    importedArray.importFromFile("test_array.txt");

    EXPECT_EQ(importedArray.getSize(), 5);
    EXPECT_EQ(importedArray[0], 10);
    EXPECT_EQ(importedArray[1], 20);
    EXPECT_EQ(importedArray[2], 30);
    EXPECT_EQ(importedArray[3], 40);
    EXPECT_EQ(importedArray[4], 50);
}

TEST(ArrayFullImportTest, ImportArrayWithFloatData) {
    ArrayFull<float> array;
    array.push(1.1f);
    array.push(2.2f);
    array.push(3.3f);
    array.exportToFile("test_float_array.txt");

    ArrayFull<float> importedArray;
    importedArray.importFromFile("test_float_array.txt");

    EXPECT_EQ(importedArray.getSize(), 3);
    EXPECT_FLOAT_EQ(importedArray[0], 1.1f);
    EXPECT_FLOAT_EQ(importedArray[1], 2.2f);
    EXPECT_FLOAT_EQ(importedArray[2], 3.3f);
}

TEST(ArrayFullImportTest, ImportArrayWithNegativeValues) {
    ArrayFull<int> array;
    array.push(-1);
    array.push(-2);
    array.push(-3);
    array.push(-4);
    array.push(-5);
    array.exportToFile("test_negative_array.txt");

    ArrayFull<int> importedArray;
    importedArray.importFromFile("test_negative_array.txt");

    EXPECT_EQ(importedArray.getSize(), 5);
    EXPECT_EQ(importedArray[0], -1);
    EXPECT_EQ(importedArray[1], -2);
    EXPECT_EQ(importedArray[2], -3);
    EXPECT_EQ(importedArray[3], -4);
    EXPECT_EQ(importedArray[4], -5);
}

TEST(ArrayFullImportTest, ImportArrayWithCharData) {
    ArrayFull<char> array;
    array.push('f');
    array.push('g');
    array.exportToFile("test_char_array.txt");

    ArrayFull<char> importedArray;
    importedArray.importFromFile("test_char_array.txt");

    EXPECT_EQ(importedArray.getSize(), 2);
    EXPECT_EQ(importedArray[0], 'f');
    EXPECT_EQ(importedArray[1], 'g');
}

TEST(ArrayFullImportTest, ImportArrayWithLargeData) {
    ArrayFull<int> array;
    const int size = 1000;

    for (int i = 0; i < size; i++) {
        array.push(size - i);
    }
    array.exportToFile("test_large_array.txt");

    ArrayFull<int> importedArray;
    importedArray.importFromFile("test_large_array.txt");
    EXPECT_EQ(importedArray.getSize(), size);

    for (int i = 0; i < size; i++) {
        EXPECT_EQ(importedArray[i], size - i);
    }
}

TEST(ArrayFullImportTest, ImportFromWrongFile) {
    ArrayFull<int> array;
    EXPECT_THROW(array.importFromFile("non_existent_file.txt"), std::runtime_error);
}
