// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(1)

// Solution dependencies
#include<iostream>
#include<string>
#include<vector>
#include<cmath>

// Solution dependencies
using std::ostream_iterator;
using std::string;
using std::stringstream;
using std::vector;
using std::min;

// Core: Manacher's algorithm to avoid duplicated comparations.
//
// Preprocess: insert # into every gaps in s via "abc" => "#a#b#c"
//             then len(s): n(even or odd) -> 2 * n + 1(odd)
//
// Visualization:
//  . . . L . . . . . . . . C . . . . . . . . R . . .
//                 j        |          k
//
//        l        ←        i        →        r
//
//  Current States: we are dealing with new_s[k] with index k
//  Definition: 1. m[i] means the radius of the max palindromic
//                 substring which takes i as the center.
//                 (m[i] = i - l = r - i)
//  Logics:
//      1. If k in i -> i + r via inside i's max pali radius
//         then
//             known_len_of_k_pali = min(m[2 * i - k], r - k)
//                                             ↑
//             (The symmetric postion(j) of k in the left of i)
//         else
//             known_len_of_k_pali = m[k] -- it's 0
//             (Can not use previous calculated results)
//      2. continue to process check palindromic rule behind
//              k + known_len_of_k_pali
// Time: O(n)
// Space: O(1)
class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.size() <= 1) return s;
    // preprocess
    stringstream ss;
    copy(s.begin(), s.end(), ostream_iterator<char>(ss, "#"));
    string new_str = "#" + ss.str();

    int str_len = new_str.size();
    vector<int> m(str_len, 0);
    int cur_center = 0, cur_radius = 0;
    int max_center = 0, max_radius = 0;
    for (int k = 1; k < str_len; ++k) {
      // 1. get known_len_of_k_pali
      int known_radius = cur_center + cur_radius > k ?
                         min(m[2 * cur_center - k], cur_center + cur_radius - k) : m[k]; // NOLINT(*)
      int left = k - known_radius;
      int right = k + known_radius;

      // 2. continue check positon behind known_len_of_k_pali
      while (right + 1 < str_len && left - 1 >= 0
             && new_str[left - 1] == new_str[right + 1]) {
        --left;
        ++right;
      }

      // change center_index if k goes out of cur_index + cur_radius
      int k_radius = right - k;
      if (right > cur_center + cur_radius) {
        cur_center = k;
        cur_radius = k_radius;
      }

      // check max_len
      if (k_radius > max_radius) {
        max_center = k;
        max_radius = k_radius;
      }
      m[k] = k_radius;
    }
    return s.substr((max_center - max_radius) / 2, max_radius);
  }
};

// Core: From current postion to try to build palindrome string
//       by expanding to two ends.
// Visualization:
//  a    b    a    b    a
//         <- i ->
// Tricks:
// 1. if s.size() <= 1, return s
// 2. if s.size() - current_position <= max_len / 2, stop searching
// 3. !!! If in s[i - > j] are all duplicated char, for all chars in this range
//        max_len = len(i -> j) + [len(? -> i - 1) + len(j + 1 -> ?)]
//                       ↑                         ↑
//                    Must Exist                Optional
//
//        0    1    2    3    4    5    6    7
//        a    b    d    d    d    d    b    a
//        ↑         ↑              ↑         ↑
//        ?         i              j         ?
//        max_len = (5 - 2 + 1) + [(1 - 0 + 1) + (7 - 6 + 1)] = 8
//
//    So, we could skip the duplicated chars
//    In addition, it will also handle odd and even scenarios at the same time.
// Time: O(n^2)
// Space: O(1)
class Solution2 {
 public:
  string longestPalindrome(string s) {
    // It must be a palindrome string
    if (s.size() <= 1) return s;

    int start = 0, max_len = 1;
    int str_len = s.size();
    for (int i = 0; i < str_len;) {
      // stop if it's impossible to find longer palindrome
      if (str_len - i <= max_len / 2) break;

      // start searching by expanding to two ends
      int left = i, right = i;
      // skip duplicated chars
      while (right + 1 < str_len && s[left] == s[right + 1]) ++right;
      i = right + 1;
      // expanding
      while (right + 1 < str_len && left - 1 >= 0
             && s[left - 1] == s[right + 1]) {
        --left;
        ++right;
      }

      // check if it's longer than current max substr
      if (right - left + 1 > max_len) {
        max_len = right - left + 1;
        start = left;
      }
    }
    return s.substr(start, max_len);
  }
};
