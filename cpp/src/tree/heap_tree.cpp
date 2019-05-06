#include "tree/heap_tree.h"

#include <iostream>

using std::cout;

HeapTree::HeapTree() : _end(_tree.getRoot()) {}
void HeapTree::heapify(const std::vector<std::string>& values) {}

void HeapTree::merge(const Heap& other) {}

std::unique_ptr<NodeInt>& HeapTree::findEnd(std::unique_ptr<NodeInt>& root) {
  if (root->_right == nullptr || root->_left == nullptr) {
    return root;
  }
  if (countElements(root->_left) > countElements(root->_right)) {
    return findEnd(root->_right);
  }
  return findEnd(root->_left);
}

std::unique_ptr<NodeInt>& HeapTree::findLast(std::unique_ptr<NodeInt>& root) {
  if (root->_right == nullptr && root->_left == nullptr) {
    return root;
  }
  if (countElements(root->_left) > countElements(root->_right)) {
    return findLast(root->_left);
  }
  return findLast(root->_right);
}

void HeapTree::insert(const std::string& value) {
  int element = std::stoi(value);
  auto node = std::make_unique<NodeInt>(element);
  if (_end == nullptr) {
    _end = std::move(node);
  } else if (_end->_left == nullptr) {
    _end->_left = std::move(node);
  } else {
    _end->_right = std::move(node);
  }
  cout << _tree.visitInOrder(";") << "\n";
  _end = std::move(findEnd(_tree.getRoot()));
  cout << _tree.visitInOrder(";") << "\n";
}

std::string HeapTree::peek() {
  auto& root = _tree.getRoot();
  if (not root) {
    return "";
  }
  return root->data();
}

std::string HeapTree::pop() {
  auto& element = _tree.getRoot();
  if (not element) {
    return "";
  }
  auto& lastElem = findLast(_tree.getRoot());

  return element->data();
}

size_t HeapTree::size() { return countElements(_tree.getRoot()); }

bool HeapTree::isEmpty() { return size() == 0; }

void HeapTree::deleteTop() {}

std::string HeapTree::replace(const std::string& value) {}

size_t HeapTree::countElements(const std::unique_ptr<NodeInt>& root) {
  if (root == nullptr) {
    return 0;
  }
  return 1 + countElements(root->_left) + countElements(root->_right);
}

void HeapTree::siftUp() {}

void HeapTree::siftDown() {}
