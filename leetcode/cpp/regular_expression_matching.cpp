// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(s.size() * p.size())
// Best solution space: O(s.size() * p.size())

// Solution dependencies
#include<string>
#include<vector>

using std::string;
using std::vector;

// Core:
// Dynamic Programming:
// 1. Subproblem: process s[i] and p[j], then check the rest parts of s, p
//    # Subproblems = s.size()
// 2. Guess:
//    2.1 p[j + 1] is *, then use or not use *
//    2.2 Otherwise, check s[i] == p[j]
//    # Choices = 2
// 3. Recurrence: dp[i][j] = 2.1 or 2.2
// 4. Order: for i = 0 -> s.size() for j = 0 -> p.size()
// 5. Solution: dp[s.size()][p.size()]

// Top-down
class Solution {
 public:
  bool isMatch(string s, string p) {
    // 0 false, 1 true, -1 unused
    memo.resize(s.size() + 1, vector<int>(p.size() + 1, -1));
    return isMatch(s, 0, p, 0);
  }

  bool isMatch(const string &s, size_t i, const string &p, size_t j) {
    if (memo[i][j] != -1) return memo[i][j];

    bool match;
    if (p.size() == j) {
      match = (s.size() == i);
    } else {
      bool first_match = (i < s.size() &&
                          (p[j] == s[i] || p[j] == '.'));
      if (j + 1 < p.size() && p[j + 1] == '*') {
        // two choices:
        // 1. use the following *, reuse current char of p
        // 2. do not use the following *, skip it by j + 2
        match = (isMatch(s, i, p, j + 2) ||
                 (first_match && isMatch(s, i + 1, p, j)));
      } else {
        // Normal move forward
        match = first_match && isMatch(s, i + 1, p, j + 1);
      }
    }
    memo[i][j] = match;
    return match;
  }

 private:
  vector<vector<int>> memo;
};

// Bottom-up
class Solution2 {
 public:
  bool isMatch(string s, string p) {
    memo.resize(s.size() + 1, vector<int>(p.size() + 1));
    memo[s.size()][p.size()] = true;

    for (int i = s.size(); i >= 0; --i) {
      for (int j = p.size() - 1; j >= 0; --j) {
        bool first_match = (i < s.size() &&
                            (s[i] == p[j] || p[j] == '.'));
        if (j + 1 < p.size() && p[j + 1] == '*') {
          memo[i][j] = memo[i][j + 2] || (first_match && memo[i + 1][j]);
        } else {
          memo[i][j] = first_match && memo[i + 1][j + 1];
        }
      }
    }
    return memo[0][0];
  }
 private:
  vector<vector<int>> memo;
};
