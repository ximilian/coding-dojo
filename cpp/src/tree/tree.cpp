#include "tree.h"
#include <iostream>

using std::cout;
using std::endl;

std::string findChildSubstring(const std::string& data, size_t index = 0) {
  size_t closingIndex = index;
  int nestedParenthesisCounter = 0;
  while (closingIndex < data.length() && nestedParenthesisCounter >= 0) {
    if (data[closingIndex] == '(') {
      nestedParenthesisCounter++;
    } else if (data[closingIndex] == ')') {
      nestedParenthesisCounter--;
    }
    closingIndex++;
  }
  if (closingIndex == index) {
    return "";
  }
  return data.substr(index, closingIndex - index - 1);
}

template <typename N>
Tree<N>::Tree(const std::string& representation) {
  buildTree(_root, representation);
}

template <typename N>
void Tree<N>::buildTree(std::unique_ptr<N>& root,
                        const std::string& representation) {
  if (!representation.empty()) {
    auto index = representation.find_first_of("(");
    std::string data = representation.substr(0, index);
    root = std::make_unique<N>(data);
    if (index != std::string::npos) {
      auto leftChild = findChildSubstring(representation, index + 1);
      buildTree(root->_left, leftChild);
      buildTree(
          root->_right,
          findChildSubstring(representation, index + leftChild.length() + 3));
    }
  }
}

template <typename N>
std::string Tree<N>::visitInOrder(const std::string& separator) {
  return visitInOrder(_root, separator);
}

template <typename N>
std::string Tree<N>::visitPreOrder(const std::string& separator) {
  return visitPreOrder(_root, separator);
}

template <typename N>
std::string Tree<N>::visitPostOrder(const std::string& separator) {
  return visitPostOrder(_root, separator);
}

template <typename N>
std::string Tree<N>::visitInOrder(const std::unique_ptr<N>& root,
                                  const std::string& separator) {
  if (root == nullptr) {
    return "";
  }
  return visitInOrder(root->_left, separator) + root->data() + separator +
         visitInOrder(root->_right, separator);
}

template <typename N>
std::string Tree<N>::visitPreOrder(const std::unique_ptr<N>& root,
                                   const std::string& separator) {
  if (root == nullptr) {
    return "";
  }
  return root->data() + separator + visitPreOrder(root->_left, separator) +
         visitPreOrder(root->_right, separator);
}

template <typename N>
std::string Tree<N>::visitPostOrder(const std::unique_ptr<N>& root,
                                    const std::string& separator) {
  if (root == nullptr) {
    return "";
  }
  return visitPostOrder(root->_left, separator) +
         visitPostOrder(root->_right, separator) + root->data() + separator;
}
