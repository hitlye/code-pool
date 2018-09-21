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
  bool isValidBST(TreeNode* root) {
    TreeNode *prev = nullptr;
    return isValidBST(root, prev);
  }

  bool isValidBST(TreeNode* root, TreeNode* &prev) { // NOLINT(*)
    if (root == nullptr) return true;
    if (!isValidBST(root->left, prev)) return false;
    if (prev != nullptr && root->val <= prev->val) return false;
    prev = root;
    return isValidBST(root->right, prev);
  }
};
