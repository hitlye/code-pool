// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n*k) k is the number of recursively call
// Best solution space: O(1)

// Solution dependencies
#include<algorithm>
#include<string>
#include<vector>

// Solution dependencies
using std::reverse;
using std::string;
using std::vector;

// Core:
// 1. Use a counter to check if current char of s cause an invalid part
// 2. Recursively handling every invalid part of s
// 3. Remove one previous ) makes current part valid, and add to answers
//    for consecutive ), we can only remove one of them.
// 4. Reverse string to reuse the above code.
// Time: O(n*k)
// Space: O(1)
class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> possible_valid_strs;
    removeInvalidParentheses(0, 0, '(', ')', &s, &possible_valid_strs);
    return possible_valid_strs;
  }

  void removeInvalidParentheses(int scan_start, int removable_start,
                                char lparen, char rparen,
                                string *pstr, vector<string> *pvec) {
    int validation_counter = 0;
    string &s = *pstr;
    for (int i = scan_start; i < s.size(); ++i) {
      if (s[i] == lparen) ++validation_counter;
      if (s[i] == rparen) --validation_counter;
      if (validation_counter >= 0) continue;
      // find all removable rparens, skip consecutive rparen
      for (int j = removable_start; j <= i; ++j) {
        if (s[j] == rparen && (j == removable_start || s[j - 1] != rparen)) {
          string valid_s = s.substr(0, j) + s.substr(j + 1);
          // since we deleted a char, the new index = old index - 1
          removeInvalidParentheses(i, j, lparen, rparen, &valid_s, pvec);
        }
      }
      return;
    }

    // now we have a ) valid string or completely valid reversed string
    reverse(s.begin(), s.end());
    if (lparen == '(') {
      // ) valid string, we have to deal with (
      removeInvalidParentheses(0, 0, ')', '(', &s, pvec);
    } else {
      // completely valid string
      pvec->emplace_back(s);
    }
  }
};

// TODO(hitlye): BFS version
