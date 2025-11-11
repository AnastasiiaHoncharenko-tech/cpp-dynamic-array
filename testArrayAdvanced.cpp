#include "gtest/gtest.h"
#include "ArrayFull.h"
#include "ArrayAdvanced.h"

using namespace ::testing;

// subArray
TEST(ArrayFullSubArrayTest, SubArrayValid) {
    ArrayFull<int> array;
    array.push(1);
    array.push(2);
    array.push(3);
    array.push(4);
    array.push(5);

    int* result = array.subArray(1, 3);

    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 3);
    EXPECT_EQ(result[2], 4);

    delete[] result;
}

TEST(ArrayFullSubArrayTest, SubArrayInvalidStart) {
    ArrayFull<int> array;
    array.push(1);
    array.push(2);
    array.push(3);
    array.push(4);
    array.push(5);

    EXPECT_THROW(array.subArray(-5, 3), std::out_of_range);
}

TEST(ArrayFullSubArrayTest, SubArrayInvalidEnd) {
    ArrayFull<int> array;
    array.push(1);
    array.push(2);
    array.push(3);
    array.push(4);
    array.push(5);

    EXPECT_THROW(array.subArray(1, 10), std::out_of_range);
}

TEST(ArrayFullSubArrayTest, SubArrayStartGreaterThanEnd) {
    ArrayFull<int> array;
    array.push(1);
    array.push(2);
    array.push(3);
    array.push(4);
    array.push(5);

    EXPECT_THROW(array.subArray(3, 1), std::out_of_range);
}

TEST(ArrayFullSubArrayTest, SubArrayValidChar) {
    ArrayFull<char> array;
    array.push('b');
    array.push('c');
    array.push('d');
    array.push('g');
    array.push('u');

    char* result = array.subArray(0, 2);

    EXPECT_EQ(result[0], 'b');
    EXPECT_EQ(result[1], 'c');
    EXPECT_EQ(result[2], 'd');

    delete[] result;
}

TEST(ArrayFullSubArrayTest, SubArrayValidFloat) {
    ArrayFull<float> array;
    array.push(1.8f);
    array.push(10.3f);
    array.push(16.7f);
    array.push(0.5f);
    array.push(3.19f);

    float* result = array.subArray(3, 4);

    EXPECT_EQ(result[0], 0.5f);
    EXPECT_EQ(result[1], 3.19f);

    delete[] result;
}

// swap
TEST(ArrayFullSwapTest, SwapValid) {
    ArrayFull<int> array;
    array.push(1);
    array.push(2);
    array.push(3);
    array.push(4);
    array.push(5);

    array.swap(1, 3);

    EXPECT_EQ(array[1], 4);
    EXPECT_EQ(array[3], 2);
}

TEST(ArrayFullSwapTest, SwapInvalidIndex) {
    ArrayFull<int> array;
    array.push(1);
    array.push(2);
    array.push(3);
    array.push(4);
    array.push(5);

    EXPECT_THROW(array.swap(-3, 3), std::out_of_range);
}

TEST(ArrayFullSwapTest, SwapSecondIndexOutOfRange) {
    ArrayFull<int> array;
    array.push(1);
    array.push(2);
    array.push(3);
    array.push(4);
    array.push(5);

    EXPECT_THROW(array.swap(1, 15), std::out_of_range);
}

TEST(ArrayFullSwapTest, SwapValidChar) {
    ArrayFull<char> array;
    array.push('b');
    array.push('c');
    array.push('d');
    array.push('g');
    array.push('u');

    array.swap(3, 4);

    EXPECT_EQ(array[3], 'u');
    EXPECT_EQ(array[4], 'g');
}

TEST(ArrayFullSwapTest, SwapValidDouble) {
    ArrayFull<double> array;
    array.push(1.8);
    array.push(10.3);
    array.push(16.7);
    array.push(0.5);
    array.push(3.19);

    array.swap(0, 2);

    EXPECT_EQ(array[0], 16.7);
    EXPECT_EQ(array[2], 1.8);
}

// removeByIndex
TEST(ArrayFullRemoveByIndexTest, RemoveByIndexValid) {
    ArrayFull<int> array;
    array.push(1);
    array.push(2);
    array.push(3);
    array.push(4);
    array.push(5);

    array.removeByIndex(2);

    EXPECT_EQ(array.getSize(), 4);
    EXPECT_EQ(array[0], 1);
    EXPECT_EQ(array[1], 2);
    EXPECT_EQ(array[2], 4);
    EXPECT_EQ(array[3], 5);
}

TEST(ArrayFullRemoveByIndexTest, RemoveByIndexInvalid) {
    ArrayFull<int> array;
    array.push(1);
    array.push(2);
    array.push(3);
    array.push(4);
    array.push(5);

    EXPECT_THROW(array.removeByIndex(5), std::out_of_range);
}

TEST(ArrayFullRemoveByIndexTest, RemoveByNegativeIndexInvalid) {
    ArrayFull<int> array;
    array.push(1);
    array.push(2);
    array.push(3);
    array.push(4);
    array.push(5);

    EXPECT_THROW(array.removeByIndex(-10), std::out_of_range);
}

TEST(ArrayFullRemoveByIndexTest, RemoveByIndexMultipleValid) {
    ArrayFull<char> array;
    array.push('b');
    array.push('c');
    array.push('d');
    array.push('g');
    array.push('u');

    array.removeByIndex(0);
    array.removeByIndex(0);

    EXPECT_EQ(array.getSize(), 3);

    array.removeByIndex(0);
    array.removeByIndex(0);

    EXPECT_EQ(array.getSize(), 1);
    EXPECT_EQ(array[0], 'u');
}

// intersect
TEST(ArrayFullIntersectTest, IntersectWithCommonElementsChar) {
    ArrayFull<char> array;
    array.push('a');
    array.push('b');
    array.push('c');
    array.push('d');

    char otherArray[] = {'b', 'c', 'e'};
    char* result = array.intersect(otherArray, 3);

    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result[0], 'b');
    EXPECT_EQ(result[1], 'c');

    delete[] result;
}

TEST(ArrayFullIntersectTest, IntersectWithCommonElementsFloat) {
    ArrayFull<float> array;
    array.push(1.1f);
    array.push(2.2f);
    array.push(3.3f);
    array.push(4.4f);

    float otherArray[] = {2.2f, 3.3f, 5.5f};
    float* result = array.intersect(otherArray, 3);

    ASSERT_NE(result, nullptr);
    EXPECT_FLOAT_EQ(result[0], 2.2f);
    EXPECT_FLOAT_EQ(result[1], 3.3f);

    delete[] result;
}

TEST(ArrayFullIntersectTest, IntersectWithNoCommonElements) {
    ArrayFull<int> array;
    array.push(7);
    array.push(8);
    array.push(9);

    int otherArray[] = {1, 2, 3};
    int* result = array.intersect(otherArray, 3);

    EXPECT_EQ(result, nullptr);
}

TEST(ArrayFullIntersectTest, IntersectWithDuplicateElements) {
    ArrayFull<int> array;
    array.push(1);
    array.push(2);
    array.push(2);
    array.push(3);

    int otherArray[] = {2, 2, 3, 4};
    int* result = array.intersect(otherArray, 4);

    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 2);
    EXPECT_EQ(result[2], 3);

    delete[] result;
}

TEST(ArrayFullIntersectTest, IntersectWithEmptyArray) {
    ArrayFull<int> array;
    array.push(1);
    array.push(2);
    array.push(3);

    int otherArray[] = {};
    int* result = array.intersect(otherArray, 0);

    EXPECT_EQ(result, nullptr);
}

TEST(ArrayFullIntersectTest, IntersectWithNegativeNumbers) {
    ArrayFull<int> array;
    array.push(-10);
    array.push(-5);
    array.push(0);
    array.push(5);

    int otherArray[] = {-5, 0, 10};
    int* result = array.intersect(otherArray, 3);

    EXPECT_EQ(result[0], -5);
    EXPECT_EQ(result[1], 0);

    delete[] result;
}

// maxSubarray
TEST(ArrayFullMaxSubarrayTest, MaxSubarrayPositive) {
    ArrayFull<int> array;
    array.push(1);
    array.push(2);
    array.push(-1);
    array.push(3);
    array.push(4);
    array.push(-2);
    array.push(6);

    int* result = array.maxSubarray();
    int expected[] = {1, 2, -1, 3, 4, -2, 6};
    int expectedSize = 7;

    for (int i = 0; i < expectedSize; i++) {
        EXPECT_EQ(result[i], expected[i]);
    }

    delete[] result;
}

TEST(ArrayFullMaxSubarrayTest, MaxSubarrayNegative) {
    ArrayFull<int> array;
    array.push(-5);
    array.push(-1);
    array.push(-3);
    array.push(-4);

    int* result = array.maxSubarray();
    int expected[] = {-1};
    int expectedSize = 1;

    for (int i = 0; i < expectedSize; i++) {
        EXPECT_EQ(result[i], expected[i]);
    }

    delete[] result;
}

TEST(ArrayFullMaxSubarrayTest, MaxSubarrayMixed) {
    ArrayFull<int> array;
    array.push(-2);
    array.push(1);
    array.push(-3);
    array.push(4);
    array.push(-1);
    array.push(2);
    array.push(1);
    array.push(-5);
    array.push(4);

    int* result = array.maxSubarray();
    int expected[] = {4, -1, 2, 1};
    int expectedSize = 4;

    for (int i = 0; i < expectedSize; ++i) {
        EXPECT_EQ(result[i], expected[i]);
    }

    delete[] result;
}

TEST(ArrayFullMaxSubarrayTest, MaxSubarraySingleElement) {
    ArrayFull<int> array;
    array.push(10);

    int* result = array.maxSubarray();

    EXPECT_EQ(result[0], 10);
    delete[] result;
}

TEST(ArrayFullMaxSubarrayTest, MaxSubarrayEmpty) {
    ArrayFull<int> array;

    int* result = array.maxSubarray();

    EXPECT_EQ(result, nullptr);
}

TEST(ArrayFullMaxSubarrayTest, MaxSubarrayChar) {
    ArrayFull<char> array;
    array.push('a');
    array.push('b');
    array.push('c');
    array.push('d');
    array.push('e');
    array.push('f');

    char* result = array.maxSubarray();

    char expected[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int expectedSize = 6;

    for (int i = 0; i < expectedSize; ++i) {
        EXPECT_EQ(result[i], expected[i]);
    }
    delete[] result;
}

TEST(ArrayFullMaxSubarrayTest, MaxSubarrayFloat) {
    ArrayFull<float> array;
    array.push(1.5f);
    array.push(2.5f);
    array.push(-1.2f);
    array.push(3.0f);
    array.push(4.5f);
    array.push(-2.1f);
    array.push(6.3f);

    float* result = array.maxSubarray();

    float expected[] = {1.5f, 2.5f, -1.2f, 3.0f, 4.5f, -2.1f, 6.3f};
    int expectedSize = 7;

    for (int i = 0; i < expectedSize; ++i) {
        EXPECT_EQ(result[i], expected[i]);
    }
    delete[] result;
}

// merge
TEST(ArrayFullMergeTest, MergeWithNonEmptyArray_Float) {
    ArrayFull<float> array;
    array.push(1.1f);
    array.push(2.2f);
    array.push(3.3f);

    float otherArray[] = {4.4f, 5.5f, 6.6f};
    array.merge(otherArray, 3);

    EXPECT_EQ(array.getSize(), 6);
    EXPECT_FLOAT_EQ(array[0], 1.1f);
    EXPECT_FLOAT_EQ(array[1], 2.2f);
    EXPECT_FLOAT_EQ(array[2], 3.3f);
    EXPECT_FLOAT_EQ(array[3], 4.4f);
    EXPECT_FLOAT_EQ(array[4], 5.5f);
    EXPECT_FLOAT_EQ(array[5], 6.6f);
}

TEST(ArrayFullMergeTest, MergeWithEmptyArray) {
    ArrayFull<int> array;
    array.push(10);
    array.push(20);

    int otherArray[] = {};
    array.merge(otherArray, 0);

    EXPECT_EQ(array.getSize(), 2);
    EXPECT_EQ(array[0], 10);
    EXPECT_EQ(array[1], 20);
}

TEST(ArrayFullMergeTest, MergeWithNonEmptyArrayChar) {
    ArrayFull<char> array;
    array.push('a');
    array.push('b');
    array.push('c');

    char otherArray[] = {'d', 'e', 'f'};
    array.merge(otherArray, 3);

    EXPECT_EQ(array.getSize(), 6);
    EXPECT_EQ(array[0], 'a');
    EXPECT_EQ(array[1], 'b');
    EXPECT_EQ(array[2], 'c');
    EXPECT_EQ(array[3], 'd');
    EXPECT_EQ(array[4], 'e');
    EXPECT_EQ(array[5], 'f');
}

TEST(ArrayFullMergeTest, MergeWithDuplicates) {
    ArrayFull<int> array;
    array.push(1);
    array.push(2);
    array.push(3);

    int otherArray[] = {2, 3, 4};
    array.merge(otherArray, 3);

    EXPECT_EQ(array.getSize(), 6);
    EXPECT_EQ(array[0], 1);
    EXPECT_EQ(array[1], 2);
    EXPECT_EQ(array[2], 3);
    EXPECT_EQ(array[3], 2);
    EXPECT_EQ(array[4], 3);
    EXPECT_EQ(array[5], 4);
}

TEST(ArrayFullMergeTest, MergeWithNegativeNumbers) {
    ArrayFull<int> array;
    array.push(-10);
    array.push(-5);

    int otherArray[] = {-20, -15, 0};
    array.merge(otherArray, 3);

    EXPECT_EQ(array.getSize(), 5);
    EXPECT_EQ(array[0], -10);
    EXPECT_EQ(array[1], -5);
    EXPECT_EQ(array[2], -20);
    EXPECT_EQ(array[3], -15);
    EXPECT_EQ(array[4], 0);
}

// forEach
TEST(ArrayFullForEachTest, ForEachValid) {
    ArrayFull<int> array;
    array.push(1);
    array.push(2);
    array.push(3);
    array.push(4);

    int sum = 0;
    array.forEach([&sum](int x) { sum += x; });

    EXPECT_EQ(sum, 10);
}

TEST(ArrayFullForEachTest, ForEachCharValid) {
    ArrayFull<char> array;
    array.push('a');
    array.push('b');
    array.push('c');
    array.push('d');

    int product = 1;
    array.forEach([&product](char x) { product *= (x - 'a' + 1); });

    EXPECT_EQ(product, 24);
}

TEST(ArrayFullForEachTest, ForEachDoubleValid) {
    ArrayFull<double> array;
    array.push(1.5);
    array.push(2.5);
    array.push(3.5);
    array.push(4.5);

    double average = 0.0;
    array.forEach([&average](double x) { average += x; });
    average /= 4;

    EXPECT_EQ(average, 3.0);
}

TEST(ArrayFullForEachTest, ForEachEmpty) {
    ArrayFull<int> array;
    int count = 0;
    array.forEach([&count](int x) { count++; });

    EXPECT_EQ(count, 0);
}

// map
TEST(ArrayFullMapTest, MapValid) {
    ArrayFull<int> array;
    array.push(1);
    array.push(2);
    array.push(3);
    array.push(4);

    int* result = array.map([](int x) { return x * 2; });

    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 4);
    EXPECT_EQ(result[2], 6);
    EXPECT_EQ(result[3], 8);

    delete[] result;
}

TEST(ArrayFullMapTest, MapEmptyArray) {
    ArrayFull<int> array;
    int* result = array.map([](int x) { return x * 2; });

    EXPECT_EQ(result, nullptr);
}

TEST(ArrayFullMapTest, MapFloatValid) {
    ArrayFull<float> array;
    array.push(1.5f);
    array.push(2.5f);
    array.push(3.5f);
    array.push(4.5f);

    float* result = array.map([](float x) { return x * x; });

    EXPECT_EQ(result[0], 2.25f);
    EXPECT_EQ(result[1], 6.25f);
    EXPECT_EQ(result[2], 12.25f);
    EXPECT_EQ(result[3], 20.25f);

    delete[] result;
}

TEST(ArrayFullMapTest, MapCharValid) {
    ArrayFull<char> array;
    array.push('a');
    array.push('b');
    array.push('c');
    array.push('d');

    char* result = array.map([](char x) { return x + 1; });

    EXPECT_EQ(result[0], 'b');
    EXPECT_EQ(result[1], 'c');
    EXPECT_EQ(result[2], 'd');
    EXPECT_EQ(result[3], 'e');

    delete[] result;
}