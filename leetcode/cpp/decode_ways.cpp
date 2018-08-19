// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(1)
// Solution dependencies
#include<string>
#include<vector>

// Solution dependencies
using std::string;
using std::vector;

// Core:
// Top-down version
// memo[i]: # of choices from i -> end
// if s[i] != 0: memo[i] = memo[i + 1] + {memo[i + 2]}
// if s[i] == 0: memo[i] = 0
// Time: O(n)
// Space: O(n)
class Solution {
 public:
  int numDecodings(const string &s) {
    vector<int> memo(s.size(), -1);
    return numDecodings(s, 0, &memo);
  }
  int numDecodings(const string &s, int start, vector<int> *pmemo) {
    if (start >= s.size()) return 1;
    if ((*pmemo)[start] != -1) return (*pmemo)[start];

    int choice_num = 0;
    if (s[start] != '0') {
      choice_num = numDecodings(s, start + 1, pmemo);
      // s[i:i+2] < "26"
      if (start + 1 < s.size() &&
          (s[start] < '2' || (s[start] == '2' && s[start + 1] <= '6'))) {
        choice_num += numDecodings(s, start + 2, pmemo);
      }
    }
    (*pmemo)[start] = choice_num;
    return choice_num;
  }
};

// Bottom-up
// We only need to maintain # of choices of s[i + 1:] and s[i + 2:]
// Time: O(n)
// Space: O(1)
class Solution2 {
 public:
  int numDecodings(string s) {
    // for s[i]
    // r1: # decoding ways for s[i + 1:]
    // r2: # decoding ways for s[i + 2:]
    int r1 = 1, r2 = 0;

    for (int i = s.size() - 1; i >= 0; --i) {
      int cur = r1;
      if (s[i] == '0') {
        cur = 0;
      } else if (i + 1 < s.size() &&
               (s[i] < '2' || (s[i] == '2' && s[i + 1] <= '6'))) {
        cur += r2;
      }
      r2 = r1;
      r1 = cur;
    }
    return r1;
  }
};
