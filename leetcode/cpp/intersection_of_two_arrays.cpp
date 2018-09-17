// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(n)
class Solution {
 public:
  vector<int> intersection(const vector<int>& nums1, const vector<int>& nums2) {
    set<int> nums(nums1.begin(), nums1.end());

    set<int> intersection_nums;
    for (auto &n : nums2) {
      if (nums.find(n) != nums.end()) intersection_nums.insert(n);
    }

    return vector<int>(intersection_nums.begin(), intersection_nums.end());
  }
};
