// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(n)

// Hash map
// k = sum(i, j) = sum(0, j) - sum(0, i)
// sum(0, i) = sum(0, j) - k
class Solution {
 public:
  int subarraySum(const vector<int>& nums, int k) {
    // key: sum from 0 - > i, value: frequency
    unordered_map<int, int> sum_frequency = {{0, 1}};
    int subarray_nums = 0;

    int sum = 0;
    for (const auto & n : nums) {
      sum += n;
      int complement = sum - k;
      const auto &found = sum_frequency.find(complement);
      if (found != sum_frequency.end()) subarray_nums += found->second;
      ++sum_frequency[sum];
    }
    return subarray_nums;
  }
};
