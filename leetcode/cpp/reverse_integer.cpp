// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(digits of x)
// Best solution space: O(1)

// Solution dependencies
#include<string>
#include<climits>

using std::string;
using std::numeric_limits;

// Core: Divide original number and build reverse number simultaneously.
//       The nth digit from right to left of x is
//       the nth dight from left to right of reverse_x.
//
// Time: O(ditis of x)
// Space: O(1)
class Solution {
 public:
  int reverse(int x) {
    int64_t x_reverse = 0;

    do {
      int d = x % 10;
      x_reverse = x_reverse * 10 + d;
    } while (x /= 10);

    if (x_reverse > INT32_MAX || x_reverse < INT32_MIN) return 0;
    return x_reverse;
  }
};

// Follow up: Can not use integer larger than 32bits
//
// We should deal with overflow when dealing with input x
//
// Time: O(digits of x)
// Space: O(1)
class Solution2 {
 public:
  int reverse(int x) {
    int32_t x_reverse = 0;

    do {
      int32_t d = x % 10;

      // check if x_reverse is potentialy going to be overflow.
      if (x_reverse > INT32_MAX / 10 || (x_reverse == INT32_MAX / 10 && d > 7))
        return 0;
      if (x_reverse < INT32_MIN / 10 || (x_reverse == INT32_MIN / 10 && d < -8))
        return 0;
      x_reverse = x_reverse * 10 + d;
    } while (x /= 10);
    return x_reverse;
  }
};
