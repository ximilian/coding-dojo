#ifndef TREE_HEAP_H_
#define TREE_HEAP_H_

#include <string>
#include <vector>

class Heap {
 public:
  virtual void insert(const std::string& value) = 0;
  virtual std::string peek() = 0;
  virtual std::string pop() = 0;
  virtual void deleteTop() = 0;
  virtual std::string replace(const std::string& value) = 0;

  virtual size_t size() = 0;
  virtual bool isEmpty() = 0;

  virtual void heapify(const std::vector<std::string>& values) = 0;
  virtual void merge(const Heap& other) = 0;

 private:
  virtual void siftUp() = 0;
  virtual void siftDown() = 0;
};

#endif