// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(xx)
// Best solution space: O(xx)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
 public:
  explicit BSTIterator(TreeNode *root) {
    inOrderTravase(root);
  }

  void inOrderTravase(TreeNode *node) {
    if (node == nullptr) return;
    inorder_travasal.push(node);
    inOrderTravase(node->left);
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !inorder_travasal.empty();
  }

  /** @return the next smallest number */
  int next() {
    TreeNode *top_node = inorder_travasal.top();
    inorder_travasal.pop();
    TreeNode *node = top_node->right;
    while (node != nullptr) {
      inorder_travasal.push(node);
      node = node->left;
    }
    return top_node->val;
  }

 private:
  stack<TreeNode*> inorder_travasal;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
