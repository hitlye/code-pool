// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(log(min(m,n)))
// Best solution space: O(1)

// Solution Dependencies
#include<vector>
#include<cmath>

using std::vector;
using std::min;
using std::max;

// Core: Select i in nums1(size: m) and j in nums2(size: n),
//       ensure i + j = m - i + n - j
//       => j = (m + n)/2 - i
//       If length is odd, median in the left part, then
//            j = (m + n + 1)/2 - i
//       In conclusion, j = (m + n + 1)/2 - i
//
// Visualization:
//    A[0] ... A[i - 1] | A[i] ... A[m - 1]
//    B[0] ... B[j - 1] | B[j] ... B[n - 1]
//
// If we can ensure i + j = m - i + n - j
// then
// Median will be (max(A[i - 1] , A[j - 1]) + min(A[i], A[j])) / 2
// if m + n is even.
// Otherwise
// Median will be max(A[i - 1], A[j - 1])
// if m + n is odd
//
// Corner case:
// 1. i = 0 or j = 0, then left part will only be one of the arrays.
// 2. i = m or j = n, then right part will only be one of the arrays.
//
// Explanation: /discuss/2481/Share-my-O(log(min(mn))-solution-with-explanation
//
// Why m <= n? To ensure the calculate of j (j = (m + n + 1) / 2 - i) in 0 -> n
//
// Time: O(log(min(m, n)))
// Space: O(1)
class Solution {
 public:
  double findMedianSortedArrays(const vector<int>& nums1,
                                const vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    // Ensure m <= n
    if (m > n) return findMedianSortedArrays(nums2, nums1);

    // Calculate two cut position, and binary search right cut position
    int lo = 0, hi = m;
    while (lo <= hi) {
      int i = lo + (hi - lo) / 2;
      int j = (m + n + 1) / 2 - i;
      // Search until nums1[i - 1] <= nums2[j] && nums2[j - 1] <= nums1[i]
      if (i > 0 && nums1[i - 1] > nums2[j]) {
        // decrease i
        hi = i - 1;
      } else if (i < m && nums2[j - 1] > nums1[i]) {
        // increase i
        lo = i + 1;
      } else {
        // get right i, and we have the following corner case
        int max_left = INT_MIN;
        int min_right = INT_MAX;

        if (i == 0) {
          max_left = nums2[j - 1];
        } else if (j == 0) {
          max_left = nums1[i - 1];
        } else {
          max_left = max(nums1[i - 1], nums2[j - 1]);
        }

        // if m + n is odd, then median is max_left
        if ((m + n) % 2 == 1) return max_left;

        if (i == m) {
          min_right = nums2[j];
        } else if (j == n) {
          min_right = nums1[i];
        } else {
          min_right = min(nums1[i], nums2[j]);
        }

        return (max_left + min_right) / 2.0;
      }
    }
  }
};

// Core: Median is at position: (m+n)/2 => k,
//       in every loop we look nums1[k/2] or nums2[k/2],
//       throw away the small one and make k = k - throwed_nums until k == 1;
// Corner Case:
//     1. the smaller array size == 0, then return larger[k - 1]
//     2. k == 1 return min(nums1[0], nums2[0])
//        - recursively ternimates condition!!!
//     3. check len = min(m, k / 2)
// Trick:
//     1. always make m <= n, if not , re-call getKthnumber(...)
//     2. call getKthNumber(...) twice to merge odd and even scenario
//
// Time: O(log(m + n))
// Space: O(1)
class Solution2 {
 public:
  // Return Kth element in sorted(nums1, nums2)
  int getKthNumber(int *nums1, int m, int *nums2, int n, int k) {
    // Ensure: m <= n for simplifying the corner case,
    // after that we could only concern about m == 0 and m < k/2
    if (m > n) return getKthNumber(nums2, n, nums1, m, k);
    if (m == 0) return nums2[k - 1];

    // Recursive call terminate condition!!
    if (k == 1) return min(nums1[0], nums2[0]);

    // Binary comparation
    int i = min(m, k / 2);
    int j = k / 2;

    if (nums1[i - 1] < nums2[j - 1]) {
      return getKthNumber(nums1 + i, m - i, nums2, n, k - i);
    } else {
      return getKthNumber(nums1, m, nums2 + j, n - j, k - j);
    }
  }

  double findMedianSortedArrays(const vector<int>& nums1,
                                const vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    // Merge odd and even scenarios
    int l = (m + n + 1) / 2;
    int r = (m + n + 2) / 2;
    return (getKthNumber(nums1.data(), m, nums2.data(), n, l)
            + getKthNumber(nums1.data(), m, nums2.data(), n, r)) / 2.0;
  }
};
