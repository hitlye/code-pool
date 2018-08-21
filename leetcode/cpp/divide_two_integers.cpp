// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(1)

// Solution dependencies
#include<limits>
#include<string>
#include<vector>

// Solution dependencies
using std::labs;
using std::numeric_limits;
using std::sort;
using std::string;
using std::vector;

// Core:
// bit manipulation: divisor << 1 means divisor * 2, then compare it
// with dividend until it's larger than dividend.
// then dividend = dividend - larger_divisor
// repeat until dividend < divisor
class Solution {
 public:
  int divide(int dividend, int divisor) {
    // corner case INT32_MIN
    if (dividend == numeric_limits<int32_t>::min() && divisor == -1)
      return numeric_limits<int32_t>::max();

    // extract sign and flip the sign of negative number
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    int64_t big_dividend = labs(dividend);
    int64_t big_divisor = labs(divisor);

    int quotient = 0;
    while (big_dividend >= big_divisor) {
      int multiples = 1;
      // when loop terminates, the multiples is the right one
      int64_t multiple_divisor = big_divisor;
      while (big_dividend >= (multiple_divisor << 1)) {
        multiple_divisor <<= 1;
        multiples <<= 1;
      }
      big_dividend -= multiple_divisor;
      quotient += multiples;
    }
    return sign * quotient;
  }
};
