// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)

// Solution dependencies
#include<iostream>
#include<string>

// Solution dependencies
using std::getline;
using std::to_string;
using std::string;
using std::stringstream;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
 public:
  // Use pre-order traversal to serialize a tree to a string.
  string serialize(TreeNode* root) {
    string encoded_tree = (root == nullptr ? "null" : to_string(root->val) + ","
                           + serialize(root->left) + ","
                           + serialize(root->right));
    return encoded_tree;
  }

  // Use pre-order traversal to deserialize a string tot tree
  TreeNode* deserialize(string data) {
    stringstream ss(data);
    char delim = ',';
    return deserialize_node(ss, delim);
  }

  TreeNode* deserialize_node(stringstream &ss, char delim) {
    string val;
    getline(ss, val, delim);
    if (val == "null") return nullptr;
    TreeNode *node = new TreeNode(stoi(val));
    node->left = deserialize_node(ss, delim);
    node->right = deserialize_node(ss, delim);
    return node;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
