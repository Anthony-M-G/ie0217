#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include "TreeNode.hpp"

class BinarySearchTree {
private:
  TreeNode *root;

  TreeNode *insert(TreeNode *node, int value);
  TreeNode *findLCA(TreeNode *node, int v1, int v2);
  void inOrderTraversal(TreeNode *node);
  bool search(TreeNode *node, int value);

public:
  BinarySearchTree();
  ~BinarySearchTree();
  void insert(int value);
  int findLowestCommonAncestor(int v1, int v2);
  void printInOrder();
};

#endif // BINARYSEARCHTREE_HPP
