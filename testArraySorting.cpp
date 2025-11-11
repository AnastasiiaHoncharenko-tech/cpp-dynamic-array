#include "gtest/gtest.h"
#include "ArraySorting.h"
#include "ArrayFull.h"

using namespace ::testing;

//quickSort
TEST(ArrayFullQuickSortTest, SortEmptyArray) {
    ArrayFull<int> array;
    array.quickSort();
    EXPECT_EQ(array.getSize(), 0);
}

TEST(ArrayFullQuickSortTest, SortSingleElementArray) {
    ArrayFull<int> array;
    array.push(8);
    array.quickSort();
    EXPECT_EQ(array[0], 8);
}

TEST(ArrayFullQuickSortTest, SortSortedArray) {
    ArrayFull<int> array;
    array.push(1);
    array.push(2);
    array.push(3);
    array.push(4);
    array.push(5);
    array.quickSort();
    EXPECT_EQ(array[0], 1);
    EXPECT_EQ(array[1], 2);
    EXPECT_EQ(array[2], 3);
    EXPECT_EQ(array[3], 4);
    EXPECT_EQ(array[4], 5);
}

TEST(ArrayFullQuickSortTest, SortUnsortedArray) {
    ArrayFull<int> array;
    array.push(3);
    array.push(1);
    array.push(4);
    array.push(5);
    array.push(2);
    array.quickSort();
    EXPECT_EQ(array[0], 1);
    EXPECT_EQ(array[1], 2);
    EXPECT_EQ(array[2], 3);
    EXPECT_EQ(array[3], 4);
    EXPECT_EQ(array[4], 5);
}

TEST(ArrayFullQuickSortTest, SortArrayWithDuplicates) {
    ArrayFull<int> array;
    array.push(50);
    array.push(0);
    array.push(50);
    array.push(100);
    array.push(0);
    array.quickSort();
    EXPECT_EQ(array[0], 0);
    EXPECT_EQ(array[1], 0);
    EXPECT_EQ(array[2], 50);
    EXPECT_EQ(array[3], 50);
    EXPECT_EQ(array[4], 100);
}

TEST(ArrayFullQuickSortTest, SortFloatingPointArray) {
    ArrayFull<double> array;
    array.push(9.0);
    array.push(1.7);
    array.push(11.1);
    array.push(15.2);
    array.push(2.3);
    array.quickSort();
    EXPECT_DOUBLE_EQ(array[0], 1.7);
    EXPECT_DOUBLE_EQ(array[1], 2.3);
    EXPECT_DOUBLE_EQ(array[2], 9.0);
    EXPECT_DOUBLE_EQ(array[3], 11.1);
    EXPECT_DOUBLE_EQ(array[4], 15.2);
}

TEST(ArrayFullQuickSortTest, SortCharArray) {
    ArrayFull<char> array;
    array.push('d');
    array.push('a');
    array.push('c');
    array.push('b');
    array.quickSort();
    EXPECT_EQ(array[0], 'a');
    EXPECT_EQ(array[1], 'b');
    EXPECT_EQ(array[2], 'c');
    EXPECT_EQ(array[3], 'd');
}

TEST(ArrayFullQuickSortTest, SortLargeArray) {
    ArrayFull<int> array;
    for (int i = 1000; i > 0; i--) {
        array.push(i);
    }
    array.quickSort();
    for (int i = 0; i < 1000; i++) {
        EXPECT_EQ(array[i], i + 1);
    }
}

TEST(ArrayFullQuickSortTest, SortArrayWithNegativeNumbers) {
    ArrayFull<int> array;
    array.push(-25);
    array.push(0);
    array.push(-30);
    array.push(70);
    array.push(3);
    array.quickSort();
    EXPECT_EQ(array[0], -30);
    EXPECT_EQ(array[1], -25);
    EXPECT_EQ(array[2], 0);
    EXPECT_EQ(array[3], 3);
    EXPECT_EQ(array[4], 70);
}
