// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(1)

// Solution dependencies
#include<utility>
#include<vector>

using std::swap;
using std::vector;

// Core:
// two pointers, i and j.
// i for loop the whole array
// j for tracking the next available position for swaping in non-zero
// Time:O(n)
// Space: O(1)
class Solution {
 public:
  void moveZeroes(vector<int>& nums) { // NOLINT(*)
    for (size_t i = 0, j = 0; i < nums.size(); ++i) {
      if (nums[i]) swap(nums[j++], nums[i]);
    }
  }
};
