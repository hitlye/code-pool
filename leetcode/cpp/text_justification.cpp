// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(1)

// Solution dependencies
#include<vector>
#include<string>

using std::vector;
using std::string;

// Core:
//   1. Calculate how many words will be included in current line in every loop
//   2. Calculate how many spaces should be put after every word
//   3. Treat last line as a special case
//   4. repeat 1 - 3
class Solution {
 public:
  vector<string> fullJustify(const vector<string>& words, int maxWidth) {
    vector<string> ans;
    // In each round, we handing a single line.
    for (size_t i = 0, n = 0; i < words.size(); i += n) {
      // Calculate how many words will put into current line.
      int line_len = 0;
      for (n = 0;
           i + n < words.size() && line_len + words[i + n].size() <= maxWidth - n; // NOLINT(*)
           ++n) {
        // line: word1 + space + word2 + space + word3
        line_len += words[i + n].size();
      }
      // Assemble line without last word
      string line = words[i];
      for (size_t k = 0; k < n - 1; ++k) {
        if (i + n == words.size()) {           // last line
          line += " ";
        } else {  // evenly distributed: left = right + 1
          int even_space_num = (maxWidth - line_len) / (n - 1);
          int extra_sapce_num = k < ((maxWidth - line_len) % (n - 1));
          line += string(even_space_num + extra_sapce_num, ' ');
        }
        line += words[i + k + 1];
      }
      // last line pading spaces to right
      line += string(maxWidth - line.size(), ' ');
      ans.emplace_back(line);
    }
    return ans;
  }
};
