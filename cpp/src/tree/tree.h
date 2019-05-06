#ifndef TREE_TREE_H_
#define TREE_TREE_H_

#include <memory>

struct Node {
  Node() = default;
  virtual std::string data() = 0;
};

struct NodeString : Node {
  using Node::Node;
  NodeString(const std::string& data) : _data(data){}
  std::string data() { return _data; }
  std::string _data;
  std::unique_ptr<NodeString> _left;
  std::unique_ptr<NodeString> _right;
};

struct NodeInt : Node {
  using Node::Node;
  NodeInt(int data) : _data(data) {}
  NodeInt(const std::string& data) : _data(std::stoi(data)) {}
  std::string data() { return std::to_string(_data); }
  int _data;
  std::unique_ptr<NodeInt> _left;
  std::unique_ptr<NodeInt> _right;
};

template<typename N>
class Tree {
 public:
  Tree() = default;
  Tree(const std::string& representation);

  std::unique_ptr<N>& getRoot() { return _root; }

  std::string visitInOrder(const std::string& separator = "");

  std::string visitPreOrder(const std::string& separator = "");

  std::string visitPostOrder(const std::string& separator = "");

 protected:
  void buildTree(std::unique_ptr<N>& root,
                 const std::string& representation);
  std::unique_ptr<N> _root;

  std::string visitInOrder(const std::unique_ptr<N>& root,
                           const std::string& separator = "");

  std::string visitPreOrder(const std::unique_ptr<N>& root,
                            const std::string& separator = "");

  std::string visitPostOrder(const std::unique_ptr<N>& root,
                             const std::string& separator = "");
};

template class Tree<NodeString>;
template class Tree<NodeInt>;

typedef Tree<NodeString> TreeString;
typedef Tree<NodeInt> TreeInt;

#endif  // TREE_TREE_H_