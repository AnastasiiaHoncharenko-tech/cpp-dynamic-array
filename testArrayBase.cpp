#include "gtest/gtest.h"
#include "ArrayBase.h"
#include "ArrayFull.h"

using namespace ::testing;

//push
TEST(ArrayFullPushTest, PushSingleElementInt) {
    ArrayFull<int> testArray(10, 15);
    testArray.push(7);
    ASSERT_EQ(testArray.getSize(), 11);
    ASSERT_EQ(testArray.getElementAt(10), 7);
}

TEST(ArrayFullPushTest, PushToEmptyArrayChar) {
    ArrayFull<char> testArray(0, ' ');
    ASSERT_EQ(testArray.getSize(), 0);
    ASSERT_EQ(testArray.getCapacity(), 0);
    testArray.push('a');
    ASSERT_EQ(testArray.getSize(), 1);
    testArray.push('b');
    ASSERT_EQ(testArray.getElementAt(0), 'a');
    ASSERT_EQ(testArray.getElementAt(1), 'b');
    ASSERT_EQ(testArray.getSize(), 2);
    ASSERT_EQ(testArray.getCapacity(), 2);
}

TEST(ArrayFullPushTest, PushMultipleElementsDouble) {
    ArrayFull<double> testArray(4);
    testArray.push(11.0001);
    testArray.push(12.5);
    ASSERT_EQ(testArray.getSize(), 2);
    ASSERT_EQ(testArray.getElementAt(0), 11.0001);
    ASSERT_EQ(testArray.getElementAt(1), 12.5);
    ASSERT_EQ(testArray.getCapacity(), 4);
}

TEST(ArrayFullPushTest, PushBeyondCapacityChar) {
    char* dynamicArray = new char[2]{'a', 'b'};
    ArrayFull<char> testArray(dynamicArray, 2);
    testArray.push('c');
    testArray.push('d');
    testArray.push('e');
    ASSERT_EQ(testArray.getSize(), 5);
    ASSERT_EQ(testArray.getElementAt(3), 'd');
    ASSERT_EQ(testArray.getElementAt(4), 'e');
    delete[] dynamicArray;
}

TEST(ArrayFullPushTest, PushAfterReachingCapacityInt) {
    ArrayFull<int> testArray(3);
    ASSERT_EQ(testArray.getCapacity(), 3);
    testArray.push(10);
    testArray.push(15);
    testArray.push(20);
    ASSERT_EQ(testArray.getCapacity(), 3);
    testArray.push(25);
    ASSERT_EQ(testArray.getCapacity(), 6);
    ASSERT_EQ(testArray.getSize(), 4);
}

//unshift
TEST(ArrayFullUnshiftTest, UnshiftSingleElementInt) {
    ArrayFull<int> testArray(3, 5);
    testArray.unshift(10);
    ASSERT_EQ(testArray.getSize(), 4);
    ASSERT_EQ(testArray.getElementAt(0), 10);
}

TEST(ArrayFullUnshiftTest, UnshiftToEmptyArrayDouble) {
    ArrayFull<double> testArray(0, 0.0);
    testArray.unshift(5.0);
    ASSERT_EQ(testArray.getSize(), 1);
    ASSERT_EQ(testArray.getElementAt(0), 5.0);
}

TEST(ArrayFullUnshiftTest, UnshiftMultipleElementsInt) {
    ArrayFull<int> testArray(3, 5);
    testArray.unshift(10);
    testArray.unshift(15);
    ASSERT_EQ(testArray.getSize(), 5);
    ASSERT_EQ(testArray.getElementAt(0), 15);
    ASSERT_EQ(testArray.getElementAt(1), 10);
}

TEST(ArrayFullUnshiftTest, UnshiftBeyondCapacityChar) {
    ArrayFull<char> testArray(2, 'x');
    testArray.unshift('y');
    testArray.unshift('z');
    testArray.unshift('w');
    ASSERT_EQ(testArray.getSize(), 5);
    ASSERT_EQ(testArray.getElementAt(0), 'w');
}

TEST(ArrayFullUnshiftTest, UnshiftAfterReachingCapacityInt) {
    ArrayFull<int> testArray(3, 5);
    testArray.unshift(10);
    testArray.unshift(15);
    testArray.unshift(20);
    ASSERT_EQ(testArray.getCapacity(), 6);
}

//pop
TEST(ArrayFullPopTest, PopFromNonEmptyArrayChar) {
    ArrayFull<char> testArray(3, 'a');
    char poppedValue = testArray.pop();
    ASSERT_EQ(poppedValue, 'a');
    ASSERT_EQ(testArray.getSize(), 2);
}

TEST(ArrayFullPopTest, PopFromSingleElementArrayInt) {
    ArrayFull<int> testArray(1, 5);
    int poppedValue = testArray.pop();
    ASSERT_EQ(poppedValue, 5);
    ASSERT_EQ(testArray.getSize(), 0);
}

TEST(ArrayFullPopTest, PopFromEmptyArrayFloat) {
    ArrayFull<float> testArray(0, 0.0);
    EXPECT_THROW({
                     try {
                         testArray.pop();
                     } catch (const std::underflow_error& e) {
                         EXPECT_STREQ(e.what(), "Pop is impossible, array is empty");
                         throw;
                     }
                 }, std::underflow_error);
}

TEST(ArrayFullPopTest, PopAfterMultipleOperationsInt) {
    ArrayFull<int> testArray(5, 10);
    testArray.push(20);
    int poppedValue = testArray.pop();
    ASSERT_EQ(poppedValue, 20);
    ASSERT_EQ(testArray.getSize(), 5);
}

TEST(ArrayFullPopTest, PopAfterReachingCapacityChar) {
    ArrayFull<char> testArray(2, 'm');
    testArray.push('n');
    testArray.push('o');
    char poppedValue = testArray.pop();
    ASSERT_EQ(poppedValue, 'o');
    ASSERT_EQ(testArray.getSize(), 3);
}

//shift
TEST(ArrayFullShiftTest, ShiftFromNonEmptyArrayInt) {
    ArrayFull<int> testArray(3, 5);
    int shiftedValue = testArray.shift();
    ASSERT_EQ(shiftedValue, 5);
    ASSERT_EQ(testArray.getSize(), 2);
}

TEST(ArrayFullShiftTest, ShiftFromSingleElementArrayDouble) {
    ArrayFull<double> testArray(1, 5.0);
    double shiftedValue = testArray.shift();
    ASSERT_EQ(shiftedValue, 5.0);
    ASSERT_EQ(testArray.getSize(), 0);
}

TEST(ArrayFullShiftTest, ShiftFromEmptyArrayInt) {
    ArrayFull<int> testArray(0, 0);
    EXPECT_THROW({
                     try {
                         testArray.shift();
                     } catch (const std::underflow_error& e) {
                         EXPECT_STREQ(e.what(), "Shift is impossible, array is empty");
                         throw;
                     }
                 }, std::underflow_error);
}

TEST(ArrayFullShiftTest, ShiftAfterMultipleOperationsChar) {
    ArrayFull<char> testArray(5, 'x');
    testArray.push('y');
    char shiftedValue = testArray.shift();
    ASSERT_EQ(shiftedValue, 'x');
    ASSERT_EQ(testArray.getSize(), 5);
}

TEST(ArrayFullShiftTest, ShiftAfterReachingCapacityLong) {
    ArrayFull<long> testArray(2, 5.0);
    testArray.push(10.0);
    testArray.push(15.0);
    double shiftedValue = testArray.shift();
    ASSERT_EQ(shiftedValue, 5.0);
    ASSERT_EQ(testArray.getSize(), 3);
}

//getElementAt
TEST(ArrayFullGetElementAtTest, GetElementFromValidIndexDouble) {
    ArrayFull<double> testArray(3, 10.0);
    ASSERT_EQ(testArray.getElementAt(1), 10.0);
}

TEST(ArrayFullGetElementAtTest, GetElementFromSingleElementArrayChar) {
    ArrayFull<char> testArray(1, 'z');
    ASSERT_EQ(testArray.getElementAt(0), 'z');
}

TEST(ArrayFullGetElementAtTest, GetElementFromOutOfRangeIndexInt) {
    ArrayFull<int> testArray(3, 5);
    EXPECT_THROW(testArray.getElementAt(5), std::out_of_range);
}

TEST(ArrayFullGetElementAtTest, GetElementAfterPushOperationFloat) {
    ArrayFull<float> testArray(3, 5.0);
    testArray.push(10.0);
    ASSERT_EQ(testArray.getElementAt(3), 10.0);
}

TEST(ArrayFullGetElementAtTest, GetElementAfterShiftOperationLong) {
    ArrayFull<long> testArray(3, 5.0);
    testArray.shift();
    ASSERT_EQ(testArray.getElementAt(0), 5.0);
}
