#include "gtest/gtest.h"
#include "tree/heap_array.h"

#include <iostream>

TEST(HeapArray_test, isEmpty_whenEmptyTree_shouldBeEmpty) {
  HeapArray heap;
  EXPECT_TRUE(heap.isEmpty());
  EXPECT_EQ(heap.peek(), "");
  EXPECT_EQ(heap.pop(), "");
}

TEST(HeapArray_test, insert_whenEmptyTree_shouldInsertANode) {
  HeapArray heap;
  heap.insert("44");
  EXPECT_FALSE(heap.isEmpty());
  EXPECT_EQ(heap.peek(), "44");
  EXPECT_EQ(heap.visitInOrder(), "44;");
}

TEST(HeapArray_test, insert_whenMultipleInsert_shouldHeapify) {
  HeapArray heap;
  heap.insert("35");
  heap.insert("44");
  EXPECT_FALSE(heap.isEmpty());
  EXPECT_EQ(heap.peek(), "44");
  EXPECT_EQ(heap.visitInOrder(), "35;44;");
  // std::cout << heap.toString() << "\n";
}

TEST(HeapArray_test, insert_whenVectorInsert_shouldHeapify) {
  HeapArray heap;
  heap.insert({"35", "33", "42", "10", "14", "19", "27", "44", "26", "31"});
  EXPECT_FALSE(heap.isEmpty());
  EXPECT_EQ(heap.peek(), "44");
  EXPECT_EQ(heap.visitInOrder(), "10;33;26;42;14;31;44;19;35;27;");
  // std::cout << heap.toString() << "\n";
}

TEST(HeapArray_test, pop_whenEmptyTree_shouldReturnEmpty) {
  HeapArray heap;
  EXPECT_TRUE(heap.isEmpty());
  EXPECT_EQ(heap.pop(), "");
  EXPECT_EQ(heap.visitInOrder(), "");
}

TEST(HeapArray_test, pop_whenSingle_shouldKeepHeap) {
  HeapArray heap;
  heap.insert(std::vector<std::string>{"35", "44"});
  EXPECT_FALSE(heap.isEmpty());
  EXPECT_EQ(heap.peek(), "44");
  EXPECT_EQ(heap.pop(), "44");
  EXPECT_EQ(heap.peek(), "35");
  EXPECT_EQ(heap.visitInOrder(), "35;");
  // std::cout << heap.toString() << "\n";
}

TEST(HeapArray_test, pop_whenMultiple_shouldKeepHeap) {
  HeapArray heap;
  heap.insert({"35", "33", "42", "10", "14", "19", "27", "44", "26", "31"});
  EXPECT_FALSE(heap.isEmpty());
  EXPECT_EQ(heap.peek(), "44");
  EXPECT_EQ(heap.visitInOrder(), "10;33;26;42;14;31;44;19;35;27;");
  // std::cout << heap.toString() << "\n";
  EXPECT_EQ(heap.pop(), "44");
  EXPECT_EQ(heap.pop(), "42");
  EXPECT_EQ(heap.visitInOrder(), "10;26;33;31;35;19;27;14;");
  EXPECT_EQ(heap.pop(), "35");
  EXPECT_EQ(heap.visitInOrder(), "26;31;10;33;19;27;14;");
  // std::cout << heap.toString() << "\n";
}
