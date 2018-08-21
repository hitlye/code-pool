// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(1)

// Solution dependencies
#include<vector>
#include<cmath>

using std::vector;
using std::min;
using std::max;

// Core: Two pointers from head and tail of heights.
//       For every i, j pair, their inner sub array
//       must have the shorter width, so in order to
//       find bigger area, we have to move i/j to find
//       the next higher vertical line.
//       Move i or j? the shorter one, since current
//       area is the max area for the shorter one in
//       this array.
//
// Time: O(n)
// Space: O(n)
class Solution {
 public:
  int maxArea(const vector<int>& height) {
    if (height.size() < 2) return 0;

    int max_area = 0;
    int lo = 0, hi = height.size() - 1;
    while (lo < hi) {
      int h = min(height[lo], height[hi]);
      int area = (hi - lo) * h;
      max_area = max(max_area, area);
      // Select the shorter one and find the next higher one
      while (lo < hi && height[lo] <= h) ++lo;
      while (lo < hi && height[hi] <= h) --hi;
    }
    return max_area;
  }
};
