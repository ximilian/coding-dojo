#ifndef TREE_HEAP_TREE_H_
#define TREE_HEAP_TREE_H_

#include "tree/heap.h"
#include "tree/tree.h"

class HeapTree : public Heap {
 public:
  HeapTree();
  virtual void insert(const std::string& value);
  virtual std::string peek();
  virtual std::string pop();
  virtual void deleteTop();
  virtual std::string replace(const std::string& value);

  virtual size_t size();
  virtual bool isEmpty();

  virtual void heapify(const std::vector<std::string>& values);
  virtual void merge(const Heap& other);

 private:
  std::unique_ptr<NodeInt>& findEnd(std::unique_ptr<NodeInt>& root);
  std::unique_ptr<NodeInt>& findLast(std::unique_ptr<NodeInt>& root);
  size_t countElements(const std::unique_ptr<NodeInt>& root);
  virtual void siftUp();
  virtual void siftDown();

  TreeInt _tree;
  std::unique_ptr<NodeInt>& _end;
};

#endif