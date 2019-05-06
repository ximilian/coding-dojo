#include "gtest/gtest.h"
#include "tree/tree.h"

TEST(TreeString_test, buildTree_whenEmptyTree_shouldBeEmpty) {
  TreeString tree{""};
  EXPECT_EQ(tree.getRoot(), nullptr);
}

TEST(TreeString_test, buildTree_whenOnlyOneNode_shouldBeOnlyRootNode) {
  TreeString tree{"A"};
  ASSERT_NE(tree.getRoot(), nullptr);
  EXPECT_EQ(tree.getRoot()->_data, "A");
}

TEST(TreeString_test, buildTree_whenChildren_shouldBuildSymmetricalTree) {
  TreeString tree{"A(B)(C)"};
  auto& root = tree.getRoot();
  ASSERT_NE(root, nullptr);
  EXPECT_EQ(root->_data, "A");
  ASSERT_NE(root->_left, nullptr);
  EXPECT_EQ(root->_left->_data, "B");
  ASSERT_NE(root->_right, nullptr);
  EXPECT_EQ(root->_right->_data, "C");
}

TEST(TreeString_test,
     buildTree_whenChildrenWithDoubleCharacter_shouldBuildSymmetricalTree) {
  TreeString tree{"A(BB)(CC)"};
  auto& root = tree.getRoot();
  ASSERT_NE(root, nullptr);
  EXPECT_EQ(root->_data, "A");
  ASSERT_NE(root->_left, nullptr);
  EXPECT_EQ(root->_left->_data, "BB");
  ASSERT_NE(root->_right, nullptr);
  EXPECT_EQ(root->_right->_data, "CC");
}

TEST(TreeString_test, buildTree_whenOnlyRightChild_shouldBuildAsymmetricalTree) {
  TreeString tree{"A()(C)"};
  auto& root = tree.getRoot();
  ASSERT_NE(root, nullptr);
  ASSERT_EQ(root->_left, nullptr);
  ASSERT_NE(root->_right, nullptr);
  EXPECT_EQ(root->_right->_data, "C");
}

TEST(TreeString_test, buildTree_whenOnlyLeftChild_shouldBuildAsymmetricalTree) {
  TreeString tree{"A(B)()"};
  auto& root = tree.getRoot();
  ASSERT_NE(root, nullptr);
  ASSERT_EQ(root->_right, nullptr);
  ASSERT_NE(root->_left, nullptr);
  EXPECT_EQ(root->_left->_data, "B");
}

TEST(TreeString_test, buildTree_whenOnlyLeftChildren_shouldBuildAsymmetricalTree) {
  TreeString tree{"A(B(D))"};
  auto& root = tree.getRoot();
  ASSERT_NE(root, nullptr);
  ASSERT_EQ(root->_right, nullptr);
  ASSERT_NE(root->_left, nullptr);
  EXPECT_EQ(root->_left->_data, "B");
}

TEST(TreeString_test, buildTree_whenMixedChildren_shouldBuildAsymmetricalTree) {
  TreeString tree{"A()(C(D))"};
  auto& root = tree.getRoot();
  ASSERT_NE(root, nullptr);
  ASSERT_EQ(root->_left, nullptr);
  ASSERT_NE(root->_right, nullptr);
  EXPECT_EQ(root->_right->_data, "C");
}

TEST(TreeString_test, buildTree_whenOnlyRightChildren_shouldBuildAsymmetricalTree) {
  TreeString tree{"A()(C()(E))"};
  auto& root = tree.getRoot();
  ASSERT_NE(root, nullptr);
  ASSERT_EQ(root->_left, nullptr);
  ASSERT_NE(root->_right, nullptr);
  EXPECT_EQ(root->_right->_data, "C");
  ASSERT_NE(root->_right->_right, nullptr);
  EXPECT_EQ(root->_right->_right->_data, "E");
}

TEST(TreeString_test, visitInOrder_whenSymmetricalTree_shouldBuildCorrectString) {
  TreeString tree{"A(B(D)(E))(C(F)(G))"};
  EXPECT_EQ(tree.visitInOrder(), "DBEAFCG");
}

TEST(TreeString_test,
     visitInOrder_whenOnlyLeftChildrenTree_shouldBuildCorrectString) {
  TreeString tree{"A(B(D))"};
  EXPECT_EQ(tree.visitInOrder(), "DBA");
}

TEST(TreeString_test,
     visitInOrder_whenOnlyRightChildrenTree_shouldBuildCorrectString) {
  TreeString tree{"A()(C()(G))"};
  EXPECT_EQ(tree.visitInOrder(), "ACG");
}

TEST(TreeString_test, visitInOrder_whenMixedTree_shouldBuildCorrectString) {
  TreeString tree{"A()(C(F)())"};
  EXPECT_EQ(tree.visitInOrder(), "AFC");
}

TEST(TreeString_test, visitPreOrder_whenSymmetricalTree_shouldBuildCorrectString) {
  TreeString tree{"A(B(D)(E))(C(F)(G))"};
  EXPECT_EQ(tree.visitPreOrder(), "ABDECFG");
}

TEST(TreeString_test,
     visitPreOrder_whenOnlyLeftChildrenTree_shouldBuildCorrectString) {
  TreeString tree{"A(B(D))"};
  EXPECT_EQ(tree.visitPreOrder(), "ABD");
}

TEST(TreeString_test,
     visitPreOrder_whenOnlyRightChildrenTree_shouldBuildCorrectString) {
  TreeString tree{"A()(C()(G))"};
  EXPECT_EQ(tree.visitPreOrder(), "ACG");
}

TEST(TreeString_test, visitPreOrder_whenMixedTree_shouldBuildCorrectString) {
  TreeString tree{"A()(C(F)())"};
  EXPECT_EQ(tree.visitPreOrder(), "ACF");
}

TEST(TreeString_test, visitPostOrder_whenSymmetricalTree_shouldBuildCorrectString) {
  TreeString tree{"A(B(D)(E))(C(F)(G))"};
  EXPECT_EQ(tree.visitPostOrder(), "DEBFGCA");
}

TEST(TreeString_test,
     visitPostOrder_whenOnlyLeftChildrenTree_shouldBuildCorrectString) {
  TreeString tree{"A(B(D))"};
  EXPECT_EQ(tree.visitPostOrder(), "DBA");
}

TEST(TreeString_test,
     visitPostOrder_whenOnlyRightChildrenTree_shouldBuildCorrectString) {
  TreeString tree{"A()(C()(G))"};
  EXPECT_EQ(tree.visitPostOrder(), "GCA");
}

TEST(TreeString_test, visitPostOrder_whenMixedTree_shouldBuildCorrectString) {
  TreeString tree{"A()(C(F)())"};
  EXPECT_EQ(tree.visitPostOrder(), "FCA");
}

TEST(TreeInt_test,
     visitInOrder_whenSymmetricalTree_shouldBuildCorrectString) {
  TreeInt tree{"1(2(4)(5))(3(6)(7))"};
  EXPECT_EQ(tree.visitInOrder(), "4251637");
}

TEST(TreeInt_test, visitPreOrder_whenSymmetricalTree_shouldBuildCorrectString) {
  TreeInt tree{"1(2(4)(5))(3(6)(7))"};
  EXPECT_EQ(tree.visitPreOrder(), "1245367");
}

TEST(TreeInt_test, visitPostOrder_whenSymmetricalTree_shouldBuildCorrectString) {
  TreeInt tree{"1(2(4)(5))(3(6)(7))"};
  EXPECT_EQ(tree.visitPostOrder(), "4526731");
}

TEST(TreeInt_test, visitInOrder_whenSymmetricalTree_shouldBuildCorrectStringWithSeparator) {
  TreeInt tree{"44(42(33(10)(26))(31(14)))(35(19)(27))"};
  EXPECT_EQ(tree.visitInOrder(";"), "10;33;26;42;14;31;44;19;35;27;");
}

TEST(TreeInt_test,
     visitPreOrder_whenSymmetricalTree_shouldBuildCorrectStringWithSeparator) {
  TreeInt tree{"44(42(33(10)(26))(31(14)))(35(19)(27))"};
  EXPECT_EQ(tree.visitPreOrder(";"), "44;42;33;10;26;31;14;35;19;27;");
}

TEST(TreeInt_test,
     visitPostOrder_whenSymmetricalTree_shouldBuildCorrectStringWithSeparator) {
  TreeInt tree{"44(42(33(10)(26))(31(14)))(35(19)(27))"};
  EXPECT_EQ(tree.visitPostOrder(";"), "10;26;33;14;31;42;19;27;35;44;");
}
