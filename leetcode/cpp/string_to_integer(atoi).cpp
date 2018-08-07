// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(1)

// Solution dependencies
#include<limits>
#include<string>

using std::string;

// Core:(C++ version)
//    1. Try to ignore all leading whitespaces
//    2. Try to extract sign char, save in neg variable
//    3. If current char is not a digit, reutrn 0
//       else
//           process one digit per loop
//           check if new int value will potentially be overflow
// Time: O(valid digits)
// Space: O(1)
class Solution {
public:
    int myAtoi(string str) {
      int32_t acc = 0, neg = 0, any = 0;

      // leading spaces
      size_t i = 0;
      while (i < str.size() && str[i] == ' ')
        ++i;
      if (i >= str.size()) return 0;

      // sign
      if (str[i] == '-') {
        neg = 1;
        ++i;
      } else if (str[i] == '+') {
        ++i;
      }

      // conversion and overflow check
      // cppcheck-suppress *
      uint32_t cutoff = neg ? static_cast<uint32_t>INT32_MIN : INT32_MAX;
      int32_t cutlim = cutoff % 10;
      cutoff /= 10;
      for (acc = 0; isdigit(str[i]); ++i) {
        int32_t d = str[i] - '0';
        if (acc > cutoff || (acc == cutoff && d > cutlim)) {
          any = -1;
          break;
        }
        acc = acc * 10 + d;
      }
      if (any < 0) return neg ? INT32_MIN : INT32_MAX;
      return neg ? -acc : acc;
    }
};

// Core:(C version)
//    1. Try to ignore all leading whitespaces
//    2. Try to extract sign char, save in neg variable
//    3. If current char is not a digit, reutrn 0
//       else
//           process one digit per loop
//           check if new int value will potentially be overflow
// Time: O(n)
// Space: O(1)
class Solution2 {
 public:
  int myAtoi(string str) {
    int32_t acc = 0, any = 0;
    bool neg = false;

    // '\0' terminates str
    const char *s = str.data();

    // leading spaces
    char c;
    do {
      c = *s++;
    } while (c == ' ');

    // sign
    if (c == '-') {
      neg = true;
      c = *s++;
    } else if (c == '+') {
      c = *s++;
    }

    // conversion and overflow check
    // cppcheck-suppress *
    uint32_t cutoff = neg ? static_cast<uint32_t>INT32_MIN : INT32_MAX;
    int32_t cutlim = cutoff % 10;
    cutoff /= 10;
    for (acc = 0; isdigit(c); c = *s++) {
      int32_t d = c - '0';
      if (acc > cutoff || (acc == cutoff && d > cutlim)) {
        any = -1;
        break;
      }
      acc = acc * 10 + d;
    }
    if (any < 0) return neg ? INT32_MIN : INT32_MAX;
    return neg ? -acc : acc;
  }
};
