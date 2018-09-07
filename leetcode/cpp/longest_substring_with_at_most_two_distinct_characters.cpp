// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(1)

// Solution dependencies
#include<string>
#include<vector>
#include<map>

using std::map;
using std::string;
using std::vector;
using std::max;

class Solution {
 public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    if (s.empty()) return 0;

    // position of the smaller recently occured distinct char
    int smaller_recent_pos = -1;
    // start position of current valid substring
    int start = 0;

    int max_len = 1;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == s[i - 1]) continue;
      if (smaller_recent_pos > -1 && s[i] != s[smaller_recent_pos]) {
        max_len = max(max_len, i - start);
        start = smaller_recent_pos + 1;
      }
      smaller_recent_pos = i - 1;
    }
    max_len = max(max_len, static_cast<int>(s.size()) - start);
    return max_len;
  }
};

class Solution2 {
 public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    if (s.empty()) return 0;

    map<char, int> occurance;
    int start = 0;
    int max_len = 0;
    int i = 0;
    while (i < s.size()) {
      if (occurance.size() <= 2) {
        occurance[s[i]] = i;
        ++i;
      }
      if (occurance.size() > 2) {
        int smaller_recent_pos = s.size();
        for (const auto &kv : occurance) {
          smaller_recent_pos = min(smaller_recent_pos, kv.second);
        }
        start = smaller_recent_pos + 1;
        occurance.erase(s[smaller_recent_pos]);
      }
      max_len = max(max_len, i - start);
    }
    return max_len;
  }
};
