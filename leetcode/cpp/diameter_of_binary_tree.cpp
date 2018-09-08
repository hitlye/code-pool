// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(1)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return 0;
    int left_depth = calMaxDepth(root->left);
    int right_depth = calMaxDepth(root->right);
    int diameter = left_depth + right_depth + 2;
    return max(diameter, max_diameter);
  }

  int calMaxDepth(TreeNode *node) {
    if (node == nullptr) return -1;
    int left_depth = calMaxDepth(node->left) + 1;
    int right_depth = calMaxDepth(node->right) + 1;
    max_diameter = max(left_depth + right_depth, max_diameter);
    return max(left_depth, right_depth);
  }

 private:
  int max_diameter = 0;
};
