// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n * m)
// Best solution space: O(n)

// Solution dependencies
#include<unordered_map>
#include<string>
#include<vector>

using std::unordered_map;
using std::string;
using std::to_string;
using std::vector;

// Core: Anagrams will be same after sorting
// Time: O(n * mlogm) m is the average length of strs
// Space: O(n)
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    size_t i = 0;
    for (auto s : strs) {
      // all anagrams will be same after that.
      sort(s.begin(), s.end());
      groups[s].emplace_back(strs[i++]);
    }

    vector<vector<string>> ret;
    for (const auto &kv : groups) {
      ret.emplace_back(kv.second);
    }
    return ret;
  }
};

// Core: Map each lowercase char to a primer number, then use the product of all chars
//       in str to represented its hashcode.
//
// Thoery basis: If a, b and c are three unique primers, then a^m * b^n != c
//
// Time: O(n * m) m is the average length of strs
// Space: O(n)
//
// Limitation(Strong): Max str is (INT_MAX / 103) of z
class Solution2 {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<size_t, vector<string>> groups;
    vector<int> hash_table = {2, 3, 5, 7, 11, 13, 17,
                              19, 23, 29, 31, 41, 43,
                              47, 53, 59, 61, 67, 71,
                              73, 79, 83, 89, 97, 101,
                              103};
    for (const auto &s : strs) {
      int hash_val = 1;
      // Compare to solution1, from O(mlogm) -> O(m)
      for (const auto &c : s) hash_val *= hash_table[c - 'a'];
      groups[hash_val].emplace_back(s);
    }

    vector<vector<string>> ret;
    for (const auto &kv : groups) {
      ret.emplace_back(kv.second);
    }
    return ret;
  }
};

// Core: Self-defined hash value = char + "_" + char_counter
//
// Time: O(n * m) m is the average length of strs
// Space: O(n)
//
// Limitation(medium): Poor efficiency in short str

class Solution3 {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (const auto &s : strs) {
      string hash_val;
      vector<size_t> counter(26, 0);
      for (const auto &c : s) {
        ++counter[c - 'a'];
      }
      for (size_t i = 0; i < counter.size(); ++i) {
        if (counter[i]) hash_val += (to_string(i) + "_" + to_string(counter[i]));
      }
      groups[hash_val].emplace_back(s);
    }

    vector<vector<string>> ret;
    for (const auto &kv : groups) {
      ret.emplace_back(kv.second);
    }
    return ret;
  }
};
