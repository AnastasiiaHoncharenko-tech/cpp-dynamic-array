#include "gtest/gtest.h"
#include "ArrayFull.h"

using namespace ::testing;

//Constructors
TEST(ArrayFullConstructorTest, DefaultConstructor) {
    ArrayFull<int> array;
    EXPECT_EQ(array.getSize(), 0);
    EXPECT_EQ(array.getCapacity(), 0);
}

TEST(ArrayFullConstructorTest, SizeValueConstructor) {
    ArrayFull<int> array(7);
    EXPECT_EQ(array.getSize(), 0);
    EXPECT_EQ(array.getCapacity(), 7);
}

TEST(ArrayFullConstructorTest, SizeValueConstructorWithValue) {
    ArrayFull<int> array(6, 10);
    EXPECT_EQ(array.getSize(), 6);
    EXPECT_EQ(array.getCapacity(), 6);
    for (int i = 0; i < 6; i++) {
        EXPECT_EQ(array[i], 10);
    }
}

TEST(ArrayFullConstructorTest, ArrayConstructor) {
    int arr[] = {1, 2, 3, 4, 5};
    ArrayFull<int> array(arr, 5);
    EXPECT_EQ(array.getSize(), 5);
    EXPECT_EQ(array[0], 1);
    EXPECT_EQ(array[3], 4);
}

TEST(ArrayFullConstructorTest, CopyConstructor) {
    ArrayFull<int> original(5, 10);
    ArrayFull<int> copy = original;
    EXPECT_EQ(copy.getSize(), 5);
    EXPECT_EQ(copy[0], 10);
}

//MoveConstructor
TEST(ArrayFullMoveConstructorTest, MoveFromEmptyArray) {
    ArrayFull<int> array1;
    ArrayFull<int> array2(std::move(array1));

    EXPECT_EQ(array1.getSize(), 0);
    EXPECT_EQ(array2.getSize(), 0);
    EXPECT_EQ(array1.getCapacity(), INITIAL_SIZE);
    EXPECT_EQ(array2.getCapacity(), INITIAL_SIZE);
}

TEST(ArrayFullMoveConstructorTest, MoveFromNonEmptyArray) {
    ArrayFull<int> array1;
    array1.push(10);
    array1.push(20);
    ArrayFull<int> array2(std::move(array1));

    EXPECT_EQ(array1.getSize(), 0);
    EXPECT_EQ(array1.getCapacity(), INITIAL_SIZE);
    EXPECT_EQ(array2.getSize(), 2);
    EXPECT_EQ(array2.getCapacity(), 2);
    EXPECT_EQ(array2[0], 10);
    EXPECT_EQ(array2[1], 20);
}

TEST(ArrayFullMoveConstructorTest, MoveArrayWithMultipleElementsChar) {
    ArrayFull<char> array1;
    array1.push('w');
    array1.push('r');
    array1.push('u');
    ArrayFull<char> array2(std::move(array1));

    EXPECT_EQ(array1.getSize(), 0);
    EXPECT_EQ(array2.getSize(), 3);
    EXPECT_EQ(array2[0], 'w');
    EXPECT_EQ(array2[1], 'r');
    EXPECT_EQ(array2[2], 'u');
}

TEST(ArrayFullMoveConstructorTest, MoveAfterPushAndPop) {
    ArrayFull<int> array1;
    array1.push(100);
    array1.push(200);
    array1.pop();
    ArrayFull<int> array2(std::move(array1));

    EXPECT_EQ(array1.getSize(), 0);
    EXPECT_EQ(array2.getSize(), 1);
    EXPECT_EQ(array2[0], 100);
}

TEST(ArrayFullMoveConstructorTest, MoveEmptyAfterCopy) {
    ArrayFull<int> array1;
    ArrayFull<int> array2(array1);
    ArrayFull<int> array3(std::move(array2));

    EXPECT_EQ(array2.getSize(), 0);
    EXPECT_EQ(array3.getSize(), 0);
    EXPECT_EQ(array3.getCapacity(), INITIAL_SIZE);
}

//CopyAssignment
TEST(ArrayFullCopyAssignmentTest, CopyEmptyArray) {
    ArrayFull<int> array1;
    ArrayFull<int> array2;
    array2 = array1;

    EXPECT_EQ(array1.getSize(), 0);
    EXPECT_EQ(array2.getSize(), 0);
    EXPECT_EQ(array1.getCapacity(), INITIAL_SIZE);
    EXPECT_EQ(array2.getCapacity(), INITIAL_SIZE);
}

TEST(ArrayFullCopyAssignmentTest, CopyNonEmptyArrayFloat) {
    ArrayFull<float> array1;
    array1.push(90.7f);
    array1.push(30.6f);
    ArrayFull<float> array2;
    array2 = array1;

    EXPECT_EQ(array1.getSize(), 2);
    EXPECT_EQ(array2.getSize(), 2);
    EXPECT_EQ(array1[0], 90.7f);
    EXPECT_EQ(array1[1], 30.6f);
    EXPECT_EQ(array2[0], 90.7f);
    EXPECT_EQ(array2[1], 30.6f);
}

TEST(ArrayFullCopyAssignmentTest, CopyArrayWithDuplicates) {
    ArrayFull<int> array1;
    array1.push(3);
    array1.push(3);
    ArrayFull<int> array2;
    array2 = array1;

    EXPECT_EQ(array1.getSize(), 2);
    EXPECT_EQ(array2.getSize(), 2);
    EXPECT_EQ(array1[0], 3);
    EXPECT_EQ(array1[1], 3);
    EXPECT_EQ(array2[0], 3);
    EXPECT_EQ(array2[1], 3);
}

TEST(ArrayFullCopyAssignmentTest, CopyArrayAndModifyOriginal) {
    ArrayFull<int> array1;
    array1.push(5);
    ArrayFull<int> array2;
    array2 = array1;
    array1.push(10);

    EXPECT_EQ(array1.getSize(), 2);
    EXPECT_EQ(array2.getSize(), 1);
    EXPECT_EQ(array1[0], 5);
    EXPECT_EQ(array1[1], 10);
    EXPECT_EQ(array2[0], 5);
}

TEST(ArrayFullCopyAssignmentTest, CopyEmptyArrayToNonEmpty) {
    ArrayFull<int> array1;
    array1.push(7);
    array1.push(8);
    ArrayFull<int> array2;
    array2 = array1;
    array1 = array1;

    EXPECT_EQ(array1.getSize(), 2);
    EXPECT_EQ(array2.getSize(), 2);
    EXPECT_EQ(array1[0], 7);
    EXPECT_EQ(array1[1], 8);
}


// MoveAssignment
TEST(ArrayFullMoveAssignmentTest, MoveEmptyArray) {
    ArrayFull<int> array1;
    ArrayFull<int> array2;
    array2 = std::move(array1);

    EXPECT_EQ(array1.getSize(), 0);
    EXPECT_EQ(array1.getCapacity(), INITIAL_SIZE);
    EXPECT_EQ(array2.getSize(), 0);
    EXPECT_EQ(array2.getCapacity(), INITIAL_SIZE);
}

TEST(ArrayFullMoveAssignmentTest, MoveNonEmptyArray) {
    ArrayFull<int> array1;
    array1.push(10);
    array1.push(20);
    ArrayFull<int> array2;
    array2 = std::move(array1);

    EXPECT_EQ(array1.getSize(), 0);
    EXPECT_EQ(array1.getCapacity(), INITIAL_SIZE);
    EXPECT_EQ(array2.getSize(), 2);
    EXPECT_EQ(array2.getCapacity(), 2);
    EXPECT_EQ(array2[0], 10);
    EXPECT_EQ(array2[1], 20);
}

TEST(ArrayFullMoveAssignmentTest, MoveArrayAfterPushAndPop) {
    ArrayFull<int> array1;
    array1.push(100);
    array1.push(200);
    array1.pop();
    ArrayFull<int> array2;
    array2 = std::move(array1);

    EXPECT_EQ(array1.getSize(), 0);
    EXPECT_EQ(array2.getSize(), 1);
    EXPECT_EQ(array2[0], 100);
}

TEST(ArrayFullMoveAssignmentTest, MoveArrayWithDuplicates) {
    ArrayFull<int> array1;
    array1.push(3);
    array1.push(3);
    ArrayFull<int> array2;
    array2 = std::move(array1);

    EXPECT_EQ(array1.getSize(), 0);
    EXPECT_EQ(array2.getSize(), 2);
    EXPECT_EQ(array2[0], 3);
    EXPECT_EQ(array2[1], 3);
}

TEST(ArrayFullMoveAssignmentTest, MoveAfterCopy) {
    ArrayFull<int> array1;
    array1.push(7);
    ArrayFull<int> array2;
    array2 = array1;
    ArrayFull<int> array3;
    array3 = std::move(array2);

    EXPECT_EQ(array2.getSize(), 0);
    EXPECT_EQ(array3.getSize(), 1);
    EXPECT_EQ(array3[0], 7);
}

//IndexOperator
TEST(ArrayFullIndexOperatorTest, AccessValidIndex) {
    ArrayFull<int> array;
    array.push(5);
    array.push(10);
    array.push(15);

    EXPECT_EQ(array[0], 5);
    EXPECT_EQ(array[1], 10);
    EXPECT_EQ(array[2], 15);
}

TEST(ArrayFullIndexOperatorTest, AccessInvalidIndexBelowMin) {
    ArrayFull<int> array;
    array.push(5);
    array.push(10);

    EXPECT_THROW(array[-1], std::out_of_range);
}

TEST(ArrayFullIndexOperatorTest, AccessInvalidIndexAboveMax) {
    ArrayFull<int> array;
    array.push(5);
    array.push(10);

    EXPECT_THROW(array[2], std::out_of_range);
}

TEST(ArrayFullIndexOperatorTest, AccessSingleElementArray) {
    ArrayFull<int> array;
    array.push(42);

    EXPECT_EQ(array[0], 42);
}

TEST(ArrayFullIndexOperatorTest, AccessEmptyArray) {
    ArrayFull<int> array;

    EXPECT_THROW(array[0], std::out_of_range);
}

//Intersect
TEST(ArrayFullIntersectTest, IntersectValid) {
    ArrayFull<int> array1;
    array1.push(1);
    array1.push(2);
    array1.push(3);
    array1.push(4);

    ArrayFull<int> array2;
    array2.push(3);
    array2.push(4);
    array2.push(5);
    array2.push(6);

    int* result = array1.intersect(array2, 4);

    EXPECT_EQ(result[0], 3);
    EXPECT_EQ(result[1], 4);

    delete[] result;
}

TEST(ArrayFullIntersectTest, IntersectNoCommonElements) {
    ArrayFull<int> array1;
    array1.push(1);
    array1.push(2);
    array1.push(3);

    ArrayFull<int> array2;
    array2.push(4);
    array2.push(5);
    array2.push(6);

    int* result = array1.intersect(array2, 3);

    EXPECT_EQ(result, nullptr);

    delete[] result;
}

TEST(ArrayFullIntersectTest, IntersectValidChar) {
    ArrayFull<char> array1;
    array1.push('a');
    array1.push('b');
    array1.push('c');
    array1.push('d');

    ArrayFull<char> array2;
    array2.push('b');
    array2.push('c');
    array2.push('p');
    array2.push('r');

    char* result = array1.intersect(array2, 4);

    EXPECT_EQ(result[0], 'b');
    EXPECT_EQ(result[1], 'c');

    delete[] result;
}

TEST(ArrayFullIntersectTest, IntersectValidLong) {
    ArrayFull<long> array1;
    array1.push(5);
    array1.push(7);
    array1.push(10);
    array1.push(4);

    ArrayFull<long> array2;
    array2.push(4);
    array2.push(4);
    array2.push(4);
    array2.push(4);

    long* result = array1.intersect(array2, 4);

    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result[0], 4);

    delete[] result;
}

//merge
TEST(ArrayFullMergeTest, MergeValid) {
    ArrayFull<int> array1;
    array1.push(1);
    array1.push(2);
    array1.push(3);

    ArrayFull<int> array2;
    array2.push(4);
    array2.push(5);
    array2.push(6);

    array1.merge(array2, 3);

    EXPECT_EQ(array1[0], 1);
    EXPECT_EQ(array1[1], 2);
    EXPECT_EQ(array1[2], 3);
    EXPECT_EQ(array1[3], 4);
    EXPECT_EQ(array1[4], 5);
    EXPECT_EQ(array1[5], 6);

}

TEST(ArrayFullMergeTest, MergeEmptyArrays) {
    ArrayFull<int> array1;
    ArrayFull<int> array2;

    array1.merge(array2, 0);

    EXPECT_EQ(array1.getSize(), 0);
}

TEST(ArrayFullMergeTest, MergeCharArrays) {
    ArrayFull<char> array1;
    array1.push('a');
    array1.push('b');
    array1.push('c');

    ArrayFull<char> array2;
    array2.push('d');
    array2.push('e');
    array2.push('f');

    array1.merge(array2, 3);

    EXPECT_EQ(array1[0], 'a');
    EXPECT_EQ(array1[1], 'b');
    EXPECT_EQ(array1[2], 'c');
    EXPECT_EQ(array1[3], 'd');
    EXPECT_EQ(array1[4], 'e');
    EXPECT_EQ(array1[5], 'f');
}

TEST(ArrayFullMergeTest, MergeDoubleArrays) {
    ArrayFull<double> array1;
    array1.push(1.1);
    array1.push(2.2);
    array1.push(3.3);

    ArrayFull<double> array2;
    array2.push(4.4);
    array2.push(5.5);
    array2.push(6.6);

    array1.merge(array2, 3);

    EXPECT_EQ(array1[0], 1.1);
    EXPECT_EQ(array1[1], 2.2);
    EXPECT_EQ(array1[2], 3.3);
    EXPECT_EQ(array1[3], 4.4);
    EXPECT_EQ(array1[4], 5.5);
    EXPECT_EQ(array1[5], 6.6);
}

//Complex
TEST(ArrayFullComplexTest, FullFunctionalityCheck1) {
    ArrayFull<int> array;

    EXPECT_EQ(array.getSize(), 0);
    EXPECT_EQ(array.getCapacity(), 0);

    array.push(10);
    array.push(20);
    array.push(30);
    EXPECT_EQ(array.getSize(), 3);
    EXPECT_EQ(array.getElementAt(0), 10);
    EXPECT_EQ(array.getElementAt(1), 20);
    EXPECT_EQ(array.getElementAt(2), 30);

    array.unshift(5);
    EXPECT_EQ(array.getSize(), 4);
    EXPECT_EQ(array.getElementAt(0), 5);
    EXPECT_EQ(array.getElementAt(1), 10);

    int poppedValue = array.pop();
    EXPECT_EQ(poppedValue, 30);
    EXPECT_EQ(array.getSize(), 3);

    int shiftedValue = array.shift();
    EXPECT_EQ(shiftedValue, 5);
    EXPECT_EQ(array.getSize(), 2);
    EXPECT_EQ(array.getElementAt(0), 10);

    EXPECT_GE(array.getCapacity(), 2);

    array.push(40);
    array.push(50);
    array.push(60);
    EXPECT_EQ(array.getSize(), 5);
    EXPECT_EQ(array.getElementAt(4), 60);
}

TEST(ArrayFullComplexTest, FullFunctionalityCheck2) {
    ArrayFull<int> array;
    array.push(10);
    array.push(20);
    array.push(30);
    array.push(40);
    array.push(50);
    array.push(10);
    array.push(20);

    EXPECT_EQ(array.find(30), 2);
    EXPECT_EQ(array.find(100), -1);

    EXPECT_EQ(array.findMax(), 50);
    EXPECT_EQ(array.findMin(), 10);

    array.reverse();
    EXPECT_EQ(array.getElementAt(0), 20);
    EXPECT_EQ(array.getElementAt(1), 10);
    EXPECT_EQ(array.getElementAt(2), 50);
    EXPECT_EQ(array.getElementAt(3), 40);
    EXPECT_EQ(array.getElementAt(4), 30);
    EXPECT_EQ(array.getElementAt(5), 20);
    EXPECT_EQ(array.getElementAt(6), 10);

    array.removeDuplicates();
    EXPECT_EQ(array.getSize(), 5);
    EXPECT_EQ(array.getElementAt(0), 20);
    EXPECT_EQ(array.getElementAt(1), 10);
    EXPECT_EQ(array.getElementAt(2), 50);
    EXPECT_EQ(array.getElementAt(3), 40);
    EXPECT_EQ(array.getElementAt(4), 30);
}

TEST(ArrayFullComplexTest, FullFunctionalityCheck3) {
    ArrayFull<char> array;
    array.push('d');
    array.push('a');
    array.push('c');
    array.push('b');
    array.push('e');

    array.quickSort();
    EXPECT_EQ(array.getElementAt(0), 'a');
    EXPECT_EQ(array.getElementAt(1), 'b');
    EXPECT_EQ(array.getElementAt(2), 'c');
    EXPECT_EQ(array.getElementAt(3), 'd');
    EXPECT_EQ(array.getElementAt(4), 'e');

    std::string filename = "test_array.txt";
    array.exportToFile(filename);

    ArrayFull<char> importedArray;
    importedArray.importFromFile(filename);

    EXPECT_EQ(importedArray.getSize(), 5);
    EXPECT_EQ(importedArray.getElementAt(0), 'a');
    EXPECT_EQ(importedArray.getElementAt(1), 'b');
    EXPECT_EQ(importedArray.getElementAt(2), 'c');
    EXPECT_EQ(importedArray.getElementAt(3), 'd');
    EXPECT_EQ(importedArray.getElementAt(4), 'e');
}

TEST(ArrayFullComplexTest, FullFunctionalityCheck4) {
    ArrayFull<float> array;
    array.push(1.1f);
    array.push(2.2f);
    array.push(3.3f);
    array.push(4.4f);
    array.push(5.5f);

    float sum = 0.0f;
    array.forEach([&sum](float num) { sum += num; });
    EXPECT_FLOAT_EQ(sum, 16.5f);

    float* mappedArray = array.map([](float num) { return num * 2.0f; });
    EXPECT_FLOAT_EQ(mappedArray[0], 2.2f);
    EXPECT_FLOAT_EQ(mappedArray[1], 4.4f);
    EXPECT_FLOAT_EQ(mappedArray[2], 6.6f);
    EXPECT_FLOAT_EQ(mappedArray[3], 8.8f);
    EXPECT_FLOAT_EQ(mappedArray[4], 11.0f);
    delete[] mappedArray;

    float* subArr = array.subArray(1, 3);
    EXPECT_FLOAT_EQ(subArr[0], 2.2f);
    EXPECT_FLOAT_EQ(subArr[1], 3.3f);
    EXPECT_FLOAT_EQ(subArr[2], 4.4f);
    delete[] subArr;

    array.swap(0, 4);
    EXPECT_FLOAT_EQ(array.getElementAt(0), 5.5f);
    EXPECT_FLOAT_EQ(array.getElementAt(4), 1.1f);

    array.removeByIndex(2);
    EXPECT_EQ(array.getSize(), 4);
    EXPECT_FLOAT_EQ(array.getElementAt(0), 5.5f);
    EXPECT_FLOAT_EQ(array.getElementAt(1), 2.2f);
    EXPECT_FLOAT_EQ(array.getElementAt(2), 4.4f);
    EXPECT_FLOAT_EQ(array.getElementAt(3), 1.1f);

    float* maxSubArr = array.maxSubarray();
    EXPECT_FLOAT_EQ(maxSubArr[0], 5.5f);
    EXPECT_FLOAT_EQ(maxSubArr[1], 2.2f);
    EXPECT_FLOAT_EQ(maxSubArr[2], 4.4f);
    EXPECT_FLOAT_EQ(maxSubArr[3], 1.1f);
    delete[] maxSubArr;
}
