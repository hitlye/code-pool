// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(n)

// Solution dependencies
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

// Core: Use the hash map to store previously checked nums
// Trick: map_key: target - num
//        map_value: index of num
//
// Time: O(n)
// Space: O(n)
class Solution {
 public:
  vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> cache;

    for (int i = 0; i < nums.size(); ++i) {
      // hit target - nums[i] in cache
      const auto got = cache.find(target - nums[i]);
      if (got != cache.end()) {
        return {got->second, i};
      }
      // not hit
      cache.insert({nums[i], i});
    }

    return {-1, -1};
  }
};

// Follow up 1. If input array is sorted and space complexity should be O(1)
// Trick: two pointers from head and tail
//
//   1, 2, 3, 4, 5, 6, 7
//   ^                 ^
//   phead             ptail
//
//  phead + ptail < target => phead++
//                > target => ptail--
// Time: O(n)
// Space: O(1)
class Solution2 {
 public:
  vector<int> twoSum(const vector<int>& nums, int target) {
    int phead = 0;
    int ptail = nums.size() - 1;

    while (phead < ptail) {
      const int sum = nums[phead] + nums[ptail];
      if (sum < target)
        ++phead;
      else if (sum > target)
        --ptail;
      else
        return {phead, ptail};
    }
    return {-1, -1};
  }
};
