// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n^2)
// Best solution space: O(1)

// Solution dependencies
#include<algorithm>
#include<string>
#include<vector>

// Solution dependencies
using std::sort;
using std::string;
using std::vector;

// Core:
// 1. make the list sorted
// 2. take a number as fixed number, then we have to
//    find the target(0 - fixed number) pair in the rest of
//    list, which is the classic 2 sum problem.
// 3. skip duplicate for both fixed number and target pair
// Time: O(n^2)
// Space: O(1)
class Solution {
 public:
  vector<vector<int>> threeSum(const vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> triplets;
    for (int i = 0; i < nums.size(); ++i) {
      if (i - 1 >= 0 && nums[i - 1] == nums[i]) continue;
      int fixed_num = nums[i];
      int target = 0 - fixed_num;
      // find all targets in a sorted list
      int start = i + 1, end = nums.size() - 1;
      vector<int> all_three_nums = {fixed_num, 0, 0};
      while (start < end) {
        if (nums[start] + nums[end] > target) {
          --end;
        } else if (nums[start] + nums[end] < target) {
          ++start;
        } else {
          all_three_nums[1] = nums[start];
          all_three_nums[2] = nums[end];
          triplets.emplace_back(all_three_nums);
          while (start < end && nums[end - 1] == nums[end]) --end;
          while (start < end && nums[start + 1] == nums[start]) ++start;
          --end;
          ++start;
        }
      }
    }

    return triplets;
  }
};
