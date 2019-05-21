#ifndef TREE_HEAP_ARRAY_H_
#define TREE_HEAP_ARRAY_H_

#include "heap.h"

class HeapArray : public Heap {
public:
  HeapArray();
  virtual void insert(const std::string &value);
  virtual void insert(const std::vector<std::string> &value);
  virtual std::string peek();
  virtual std::string pop();
  virtual void deleteTop();
  virtual std::string replace(const std::string &value);

  virtual size_t size();
  virtual bool isEmpty();

  virtual void heapify(const std::vector<std::string> &values);
  virtual void merge(const Heap &other);

  virtual std::string visitInOrder(const std::string &separator = ";");

  std::string toString();

private:
  virtual void siftUp();
  virtual void siftDown();
  void siftUp(int index);
  void siftDown(int index);
  std::string visitInOrder(int index, const std::string &separator);
  std::string toString(const std::string &prefix, int index, bool isLeft);

  std::vector<int> _tree;
};

#endif