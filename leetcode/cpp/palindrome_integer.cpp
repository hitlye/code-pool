// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n/2)
// Best solution space: O(1)

// Solution dependencies
#include<limits>
#include<string>

using std::string;
using std::to_string;

// Core:
//    1. int -> str
//    2. two pointer from left and right
// Time: O(2n)
// Space: O(n)
class Solution {
 public:
  bool isPalindrome(int x) {
    string s = to_string(x);
    int lo = 0, hi = s.size() - 1;
    while (lo < hi) {
      if (s[lo] != s[hi]) return false;
      ++lo;
      --hi;
    }
    return true;
  }
};

// Follow up 1: no conversion from int -> str
//    1. reverse x
//    2. compare
// Time: O(n)
// Space: O(1)
class Solution2 {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    int64_t x_reverse = 0;
    int copy = x;
    do {
      x_reverse = x_reverse * 10 + copy % 10;
    } while (copy /= 10);
    return x == x_reverse;
  }
};

// Follow up 2: speed up follow up 1
//     we only reverse half digits of int.
//     !!!number ends with 0 are corner case!!!
// Time: O(n)
// Space: O(1)
class Solution3 {
 public:
  bool isPalindrome(int x) {
    // e.g. 12210 is corner case, since the last 0 will be ignore
    // and we are able to tell it only if reverse all digits
    if (x < 0 || (x > 0 && x % 10 == 0)) return false;

    int64_t x_reverse = 0;
    do {
      x_reverse = x_reverse * 10 + x % 10;
    } while ((x /= 10) > x_reverse);
    // odd and even cases
    return (x == x_reverse) || (x == x_reverse / 10);
  }
};
