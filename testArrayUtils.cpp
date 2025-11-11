#include "gtest/gtest.h"
#include "ArrayUtils.h"
#include "ArrayFull.h"

using namespace ::testing;

//find
TEST(ArrayFullFindTest, FindExistingElementInt) {
    ArrayFull<int> testArray(3, 10);
    ASSERT_EQ(testArray.find(10), 0);
}

TEST(ArrayFullFindTest, FindNonExistingElementFloat) {
    ArrayFull<float> testArray(3, 5.0);
    ASSERT_EQ(testArray.find(10.5), -1);
}

TEST(ArrayFullFindTest, FindInEmptyArrayInt) {
    ArrayFull<int> testArray(0, 0);
    ASSERT_EQ(testArray.find(5), -1);
}

TEST(ArrayFullFindTest, FindAfterPushOperationChar) {
    ArrayFull<char> testArray(2, 'm');
    testArray.push('n');
    ASSERT_EQ(testArray.find('n'), 2);
}

TEST(ArrayFullFindTest, FindMultipleOccurrencesChar) {
    ArrayFull<char> testArray(5, 'o');
    testArray.push('o');
    ASSERT_EQ(testArray.find('o'), 0);
}

//findMax
TEST(ArrayFullFindMaxTest, FindMaxInArrayChar) {
    ArrayFull<char> testArray(3, 'b');
    testArray.push('z');
    testArray.push('m');
    ASSERT_EQ(testArray.findMax(), 'z');
}

TEST(ArrayFullFindMaxTest, FindMaxInSingleElementArrayDouble) {
    ArrayFull<double> testArray(1, 5.5);
    ASSERT_EQ(testArray.findMax(), 5.5);
}

TEST(ArrayFullFindMaxTest, FindMaxInEmptyArrayLong) {
    ArrayFull<long> testArray(0, 0.0);
    EXPECT_THROW({
                     try {
                         testArray.findMax();
                     } catch (const std::underflow_error& e) {
                         EXPECT_STREQ(e.what(), "Finding of maximum is impossible, array is empty");
                         throw;
                     }
                 }, std::underflow_error);
}

TEST(ArrayFullFindMaxTest, FindMaxAfterPushOperationInt) {
    ArrayFull<int> testArray(2, 5);
    testArray.push(20);
    testArray.push(10);
    ASSERT_EQ(testArray.findMax(), 20);
}

TEST(ArrayFullFindMaxTest, FindMaxAfterShiftOperationFloat) {
    ArrayFull<float> testArray(3, 10.0);
    testArray.shift();
    ASSERT_EQ(testArray.findMax(), 10.0);
}

//findMin
TEST(ArrayFullFindMinTest, FindMinInArrayFloat) {
    ArrayFull<float> testArray(3, 10.5);
    testArray.push(5.5);
    testArray.push(15.5);
    ASSERT_EQ(testArray.findMin(), 5.5);
}

TEST(ArrayFullFindMinTest, FindMinInSingleElementArrayInt) {
    ArrayFull<int> testArray(1, 5);
    ASSERT_EQ(testArray.findMin(), 5);
}

TEST(ArrayFullFindMinTest, FindMinInEmptyArrayChar) {
    ArrayFull<char> testArray(0, ' ');
    EXPECT_THROW({
                     try {
                         testArray.findMin();
                     } catch (const std::underflow_error& e) {
                         EXPECT_STREQ(e.what(), "Finding of minimum is impossible, array is empty");
                         throw;
                     }
                 }, std::underflow_error);
}

TEST(ArrayFullFindMinTest, FindMinAfterPushOperationChar) {
    ArrayFull<char> testArray(2, 'g');
    testArray.push('a');
    testArray.push('k');
    ASSERT_EQ(testArray.findMin(), 'a');
}

TEST(ArrayFullFindMinTest, FindMinAfterShiftOperationDouble) {
    ArrayFull<double> testArray(3, 15.0);
    testArray.shift();
    ASSERT_EQ(testArray.findMin(), 15.0);
}

//reverse
TEST(ArrayFullReverseTest, ReverseArrayInt) {
    ArrayFull<int> testArray(2, 10);
    testArray.push(15);
    testArray.reverse();
    ASSERT_EQ(testArray.getElementAt(0), 15);
    ASSERT_EQ(testArray.getElementAt(1), 10);
    ASSERT_EQ(testArray.getElementAt(2), 10);
}

TEST(ArrayFullReverseTest, ReverseSingleElementArrayLong) {
    ArrayFull<long> testArray(1, 5.0);
    testArray.reverse();
    ASSERT_EQ(testArray.getElementAt(0), 5.0);
}

TEST(ArrayFullReverseTest, ReverseEmptyArrayInt) {
    ArrayFull<int> testArray(0, 0);
    testArray.reverse();
    ASSERT_EQ(testArray.getSize(), 0);
}

TEST(ArrayFullReverseTest, ReverseArrayAfterPushChar) {
    ArrayFull<char> testArray(3);
    testArray.push('a');
    testArray.push('b');
    testArray.push('c');
    testArray.reverse();
    ASSERT_EQ(testArray.getElementAt(0), 'c');
    ASSERT_EQ(testArray.getElementAt(1), 'b');
    ASSERT_EQ(testArray.getElementAt(2), 'a');
}

TEST(ArrayFullReverseTest, ReverseArrayAfterMultipleOperationsDouble) {
    ArrayFull<double> testArray(4);
    testArray.push(10.0);
    testArray.push(20.0);
    testArray.reverse();
    testArray.push(30.0);
    testArray.push(40.0);
    ASSERT_EQ(testArray.getElementAt(0), 20.0);
    ASSERT_EQ(testArray.getElementAt(3), 40.0);
}

//removeDuplicates
TEST(ArrayFullRemoveDuplicatesTest, RemoveDuplicatesFromArrayChar) {
    ArrayFull<char> testArray(5, 'a');
    testArray.push('a');
    testArray.removeDuplicates();
    ASSERT_EQ(testArray.getSize(), 1);
}

TEST(ArrayFullRemoveDuplicatesTest, RemoveDuplicatesInSingleElementArray) {
    ArrayFull<int> testArray(1, 5);
    testArray.removeDuplicates();
    ASSERT_EQ(testArray.getSize(), 1);
}

TEST(ArrayFullRemoveDuplicatesTest, RemoveDuplicatesInEmptyArrayChar) {
    ArrayFull<char> testArray(0, ' ');
    testArray.removeDuplicates();
    ASSERT_EQ(testArray.getSize(), 0);
}

TEST(ArrayFullRemoveDuplicatesTest, RemoveDuplicatesAfterPushFloat) {
    ArrayFull<float> testArray(2, 2.5);
    testArray.push(2.5);
    testArray.push(3.5);
    testArray.removeDuplicates();
    ASSERT_EQ(testArray.getSize(), 2);
}

TEST(ArrayFullRemoveDuplicatesTest, RemoveDuplicatesAfterMultiplePushDouble) {
    ArrayFull<double> testArray(3, 7.7);
    testArray.push(7.7);
    testArray.push(7.7);
    testArray.push(8.8);
    testArray.push(8.8);
    testArray.push(8.8);
    testArray.push(1.5);
    testArray.removeDuplicates();
    ASSERT_EQ(testArray.getSize(), 3);
}
