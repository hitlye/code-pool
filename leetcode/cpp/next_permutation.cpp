// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(1)

// Solution dependencies
#include<string>
#include<vector>

// Solution dependencies
using std::reverse;
using std::swap;
using std::string;
using std::vector;

// Core:
// 1. From size->0, find first nums[i] > nums[i - 1]
// 2. Swap(nums[i - 1], first num > nums[i - 1] in i -> end),
//    and reverse nums[i:], since it is descrese sequence
// e.g.
// 1 3 5 4 3 2 1   --> 1 4 1 2 3 3 5
//     ↑ ↑
//     i fisrt
// Time: O(n)
// Space: O(1)
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {   // NOLINT(*)
    int index = -1;
    for (int i = nums.size() - 1; i > 0; --i) {
      if (nums[i] > nums[i - 1]) {
        index = i;
        break;
      }
    }
    if (index == -1) {
      reverse(nums.begin(), nums.end());
      return;
    }
    for (int j = nums.size() - 1; j >= index; --j) {
      if (nums[j] > nums[index - 1]) {
        swap(nums[j], nums[index - 1]);
        reverse(nums.begin() + index, nums.end());
        break;
      }
    }
  }
};

// Core:
// 1. From size->0, for position i, find first j in size->i + 1,
//    ensure nums[i] < nums[j]
// 2. Swap(nums[i], nums[j]), and reverse nums[i:], since j->end
//    are dcrease sequence
// e.g.
// 1 3 5 4 3 2 1   --> 1 4 1 2 3 3 5
//   ↑   ↑
//   i   j
// Time: O(n^2)
// Space: O(1)
class Solution2 {
 public:
  void nextPermutation(vector<int>& nums) { // NOLINT(*)
    for (int i = nums.size() - 1; i >= 0; --i) {
      bool is_found = false;
      int j;
      for (j = nums.size() - 1; j > i; --j) {
        if (nums[i] < nums[j]) {
          is_found = true;
          break;
        }
      }
      if (is_found) {
        // swap(nums[i], nums[j])
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
        return;
      }
    }
    reverse(nums.begin(), nums.end());
  }
};
