// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n) n is the length
// Best solution space: O(1)

// Solution dependencies
#include<map>
#include<string>
#include<vector>

using std::map;
using std::string;
using std::vector;


// Core: Sliding Window
// Time: O(n) n is the length of s
// Space: O(1)
class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    // count letter occurance of pattern
    map<char, int> letter_counter;
    for (const auto &c : p) ++letter_counter[c];

    // sliding window parameters
    int begin = 0, end = 0;
    int len = letter_counter.size();

    vector<int> anagram_start;
    while (end < s.size()) {
      auto found_end = letter_counter.find(s[end]);
      if (found_end != letter_counter.end()) {
        if (--found_end->second == 0) --len;
      }
      ++end;

      // we have a window now
      while (len == 0) {
        // a valid anagram
        if (end - begin == p.size()) anagram_start.emplace_back(begin);
        // slide window
        auto found_begin = letter_counter.find(s[begin]);
        if (found_begin != letter_counter.end()) {
          if (++found_begin->second > 0) ++len;
        }
        ++begin;
      }
    }
    return anagram_start;
  }
};
