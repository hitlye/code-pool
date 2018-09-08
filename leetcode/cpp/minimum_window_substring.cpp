// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(len(s) + len(t))
// Best solution space: O(len(t))

// Solution dependencies
#include<string>
#include<map>

using std::map;
using std::string;
using std::max;

class Solution {
 public:
  string minWindow(string s, string t) {
    // two pointer of window
    int left = 0, right = 0;

    map<char, int> t_chars_map;
    for (const auto& c : t) ++t_chars_map[c];

    map<char, int> window_chars_map;
    int window_size = 0;
    int min_left = 0, min_len = s.size() + 1;
    while (right < s.size()) {
      char c = s[right];
      // put the same char into window
      if (t_chars_map.find(c) != t_chars_map.end()) {
        ++window_chars_map[c];
        if (window_chars_map[c] == t_chars_map[c]) ++window_size;
      }

      // include all chars of t
      while (window_size == t_chars_map.size()) {
        int current_len = right - left + 1;
        if (current_len < min_len)  {
          min_left = left;
          min_len = current_len;
        }
        if (window_chars_map.find(s[left]) != window_chars_map.end() &&
            --window_chars_map[s[left]] < t_chars_map[s[left]]) --window_size;
        ++left;
      }
      ++right;
    }
    return min_len > s.size() ? "" : s.substr(min_left, min_len);
  }
};
