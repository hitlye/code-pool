// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(1)

// Solution dependencies
#include<vector>

using std::vector;
using std::swap;

// Core: quick-select
// Time: O(n) T(n) = T(n/2) + O(n)
// Space: O(1)
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) { // NOLINT(*)
    int lo = 0, hi = nums.size() - 1;
    // array index starts with 0
    k = k - 1;
    while (true) {
      int p = partition(nums, lo, hi);
      if (p > k) {
        hi = p - 1;
      } else if (p < k) {
        lo = p + 1;
      } else {
        break;
      }
    }
    return nums[k];
  }

  int partition(vector<int>& nums, int lo, int hi) { // NOLINT(*)
    int l = lo + 1, h = hi;
    int pivot = nums[lo];

    while (l <= h) {
      while (l <= h && nums[l] >= pivot) ++l;
      while (l <= h && nums[h] <= pivot) --h;
      if (l <= h) swap(nums[l], nums[h]);
    }
    swap(nums[lo], nums[h]);
    return h;
  }
};
