#include "tree/heap_array.h"

#include <iostream>

using std::cout;

HeapArray::HeapArray() {}
void HeapArray::heapify(const std::vector<std::string>& values) {}

void HeapArray::merge(const Heap& other) {}

// std::unique_ptr<NodeInt>& HeapArray::findEnd(std::unique_ptr<NodeInt>& root)
// {
//   if (root->_right == nullptr || root->_left == nullptr) {
//     return root;
//   }
//   if (countElements(root->_left) > countElements(root->_right)) {
//     return findEnd(root->_right);
//   }
//   return findEnd(root->_left);
// }

// std::unique_ptr<NodeInt>& HeapArray::findLast(std::unique_ptr<NodeInt>& root)
// {
//   if (root->_right == nullptr && root->_left == nullptr) {
//     return root;
//   }
//   if (countElements(root->_left) > countElements(root->_right)) {
//     return findLast(root->_left);
//   }
//   return findLast(root->_right);
// }

void HeapArray::insert(const std::string& value) {
  int element = std::stoi(value);
  _tree.push_back(element);
  siftUp();
}

std::string HeapArray::peek() {
  if (isEmpty()) {
    return "";
  }
  return std::to_string(_tree[0]);
}

std::string HeapArray::pop() {
  auto elem = peek();
  if (_tree.size() <= 1) {
    _tree.clear();
  } else {
    _tree[0] = _tree.back();
    _tree.pop_back();
  }
  siftDown();

  return elem;
}

size_t HeapArray::size() { return _tree.size(); }

bool HeapArray::isEmpty() { return _tree.empty() == 0; }

void HeapArray::deleteTop() {}

std::string HeapArray::replace(const std::string& value) {}

// size_t HeapArray::countElements(const std::unique_ptr<NodeInt>& root) {
//   if (root == nullptr) {
//     return 0;
//   }
//   return 1 + countElements(root->_left) + countElements(root->_right);
// }

void HeapArray::siftUp() { siftUp(0); }

void HeapArray::siftUp(int index) {
  if (index <= 0) {
    return;
  }
  int parent = (index - 1) / 2;
  if (_tree[index] < _tree[parent]) {
    std::swap(_tree[index], _tree[parent]);
    siftUp(parent);
  }
}

void HeapArray::siftDown() { siftDown(0); }

void HeapArray::siftDown(int index) {}

std::string HeapArray::visitInOrder(const std::string& separator) {
  return visitInOrder(0, separator);
}

std::string HeapArray::visitInOrder(int index, const std::string& separator) {
  if (index >= _tree.size()) {
    return "";
  }
  return visitInOrder((2 * index) + 1, separator) + std::to_string(index) +
         visitInOrder((2 * index) + 2, separator);
}