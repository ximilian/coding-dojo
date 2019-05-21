#include "tree/heap_array.h"

#include <iostream>
#include <sstream>

using std::cout;

HeapArray::HeapArray() {}
void HeapArray::heapify(const std::vector<std::string> &values) {}

void HeapArray::merge(const Heap &other) {}

void HeapArray::insert(const std::string &value) {
  int element = std::stoi(value);
  _tree.push_back(element);
  siftUp();
}

void HeapArray::insert(const std::vector<std::string> &value) {
  for (auto item : value) {
    insert(item);
  }
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
    siftDown();
  }

  return elem;
}

size_t HeapArray::size() { return _tree.size(); }

bool HeapArray::isEmpty() { return _tree.empty(); }

void HeapArray::deleteTop() {}

std::string HeapArray::replace(const std::string &value) { return ""; }

int leftIndex(int index) { return index * 2 + 1; }

int rightIndex(int index) { return leftIndex(index) + 1; }

void HeapArray::siftUp() { siftUp(_tree.size() - 1); }

void HeapArray::siftUp(int index) {
  if (index <= 0) {
    return;
  }
  int parent = (index - 1) / 2;
  if (_tree[index] > _tree[parent]) {
    std::swap(_tree[index], _tree[parent]);
    siftUp(parent);
  }
}

void HeapArray::siftDown() { siftDown(0); }

void HeapArray::siftDown(int index) {
  if (index >= _tree.size()) {
    return;
  }
  int left_child = leftIndex(index);
  int right_child = rightIndex(index);
  int largest = index;
  if (left_child < static_cast<int>(_tree.size()) &&
      _tree[largest] < _tree[left_child]) {
    largest = left_child;
  }
  if (right_child < static_cast<int>(_tree.size()) &&
      _tree[largest] < _tree[right_child]) {
    largest = right_child;
  }
  if (largest != static_cast<int>(index)) {
    std::swap(_tree[largest], _tree[index]);
    siftDown(largest);
  }
}

std::string HeapArray::visitInOrder(const std::string &separator) {
  return visitInOrder(0, separator);
}

std::string HeapArray::visitInOrder(int index, const std::string &separator) {
  if (index >= static_cast<int>(_tree.size())) {
    return "";
  }
  return visitInOrder((2 * index) + 1, separator) +
         std::to_string(_tree[index]) + separator +
         visitInOrder((2 * index) + 2, separator);
}

std::string HeapArray::toString() { return toString("", 0, false); }

std::string HeapArray::toString(const std::string &prefix, int index,
                                bool isLeft) {
  std::stringstream result;
  if (index < static_cast<int>(_tree.size())) {
    result << prefix;
    result << (isLeft ? "├──" : "└──");

    result << _tree[index] << "\n";

    result << toString(prefix + (isLeft ? "│   " : "    "), leftIndex(index),
                       true);
    result << toString(prefix + (isLeft ? "│   " : "    "), rightIndex(index),
                       false);
  }
  return result.str();
}
