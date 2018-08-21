// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(1)

// Solution dependencies
#include<string>

// Solution dependencies
using std::string;

// TODO(hitlye): add DFA version and REGEX version
class Solution {
 public:
  bool isNumber(string s) {
    int i = 0;
    while (i < s.size() && isspace(s[i])) ++i;
    if (i == s.size()) return false;

    if (s[i] == '-' || s[i] == '+') ++i;
    for (; i < s.size() && isdigit(s[i]); ++i) {}
    if (s[i] == '.') {
      ++i;
      if ((i - 2 < 0 || !isdigit(s[i - 2])) && (i >= s.size() || !isdigit(s[i]))) return false; // NOLINT(*)
      for (; i < s.size() && isdigit(s[i]); ++i) {}
    }
    if (s[i] == 'e' || s[i] == 'E') {
      if (i - 1 < 0 || !isdigit(s[i - 1])) {
        if (s[i - 1] != '.' || !isdigit(s[i - 2])) return false;
      }
      ++i;
      if (s[i] == '-' || s[i] == '+') ++i;
      if (!isdigit(s[i])) return false;
      for (; i < s.size() && isdigit(s[i]); ++i) {}
    }

    while (i < s.size() && isspace(s[i])) ++i;
    return i == s.size();
  }
};
