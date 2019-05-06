#include "gtest/gtest.h"
#include "tree/heap_array.h"

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
  EXPECT_EQ(heap.pop(), "44");
  EXPECT_EQ(heap.visitInOrder(), "44;");
}

TEST(HeapArray_test, insert_whenMultipleInsert_shouldHeapify) {
  HeapArray heap;
  heap.insert("35");
  heap.insert("44");
  EXPECT_FALSE(heap.isEmpty());
  EXPECT_EQ(heap.peek(), "44");
  EXPECT_EQ(heap.pop(), "44");
  EXPECT_EQ(heap.visitInOrder(), "35;44;");
}
