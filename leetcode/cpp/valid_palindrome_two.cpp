// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(1)

// Solution dependencies
#include<string>

// Solution dependencies
using std::string;

// Core:
//    scan from both head and tail, if encounter not match char,
//    record it. If encounter twice, return false
// Time: O(n) since at most once
// Space: O(1)
class Solution {
 public:
  bool validPalindrome(string s) {
    return validPalindrome(s, 0, s.size() - 1, false);
  }

  bool validPalindrome(string s, int left, int right, bool is_second) {
    while (left <= right && s[left] == s[right]) {
      ++left;
      --right;
    }
    if (left > right) return true;
    if (s[left] != s[right]) {
      if (is_second) return false;
      return (validPalindrome(s, left + 1, right, true) ||
              validPalindrome(s, left, right - 1, true));
    }
  }
};

// Iterate version
class Solution2 {
 public:
  bool validPalindrome(string s) {
    int start = 0, end = s.size() - 1;
    findLongestPalindrome(s, start, end);

    int i_start = start + 1, i_end = end;
    int j_start = start, j_end = end - 1;
    findLongestPalindrome(s, i_start, i_end);
    findLongestPalindrome(s, j_start, j_end);
    return i_start > i_end || j_start > j_end;
  }

  void findLongestPalindrome(string &s, int &start, int &end) { // NOLINT(*)
    while (start <= end && s[start] == s[end]) {
      ++start;
      --end;
    }
  }
};
