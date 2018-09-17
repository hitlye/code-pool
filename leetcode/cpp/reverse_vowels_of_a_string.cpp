// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(xx)
// Best solution space: O(xx)

// Two pointer keeps track of vowels
class Solution {
 public:
  string reverseVowels(string s) {
    set<char> vowels_table = {'a', 'e', 'i', 'o', 'u'};

    int l = 0, r = s.size() - 1;
    while (l < r) {
      while (l < r && vowels_table.find(tolower(s[l])) == vowels_table.end()) ++l; // NOLINT(*)
      while (l < r && vowels_table.find(tolower(s[r])) == vowels_table.end()) --r; // NOLINT(*)
      // exchange these two vowels
      swap(s[l], s[r]);
      ++l;
      --r;
    }
    return s;
  }
};
