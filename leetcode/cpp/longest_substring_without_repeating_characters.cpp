// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(n)

// Solution dependencies
#include<unordered_map>
#include<string>
#include<algorithm>

using std::unordered_map;
using std::string;
using std::max;

// Core: A pointer to maintain current non-repeated substr head pos.
//       +
//       A map to record previous all visited chars and their positions.
//
// Visualization:
// p          w          a          w              k
// ↑          ↑                     ↑
// startp  previous                 i
//
// Current sub string len: i - startp
// Then set startp = previous + 1
//
// Time: O(n)
// Space: O(n)
class Solution {
 public:
  int lengthOfLongestSubstring(const string &s) {
    unordered_map<char, size_t> visited_chars;
    size_t startp = 0, max_len = 0;

    for (size_t i = 0; i < s.size(); ++i) {
      const auto &found = visited_chars.find(s[i]);
      if (found != visited_chars.end() && found->second >= startp) {
        // Find first duplicated
        max_len = max(max_len, i - startp);
        startp = found->second + 1;
      }
      visited_chars[s[i]] = i;
    }

    // Above loop has two termination scenarios
    return max(max_len, s.size() - startp);
  }
};
