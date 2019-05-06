#include "gtest/gtest.h"
#include "tree/heap_tree.h"

TEST(HeapTree_test, isEmpty_whenEmptyTree_shouldBeEmpty) {
  HeapTree heap;
  EXPECT_TRUE(heap.isEmpty());
  EXPECT_EQ(heap.peek(), "");
  EXPECT_EQ(heap.pop(), "");
}

TEST(HeapTree_test, insert_whenEmptyTree_shouldInsertANode) {
  HeapTree heap;
  heap.insert("44");
  EXPECT_FALSE(heap.isEmpty());
  EXPECT_EQ(heap.peek(), "44");
  EXPECT_EQ(heap.pop(), "44");
}

TEST(HeapTree_test, size_whenEmptyTree_shouldBeEmpty) {
  HeapTree heap;
  heap.insert("44");
  EXPECT_EQ(heap.size(), 1);
}
