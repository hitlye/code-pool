// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n) with few cache misses
// Best solution space: O(1)

// Solution dependencies
#include<string>
#include<vector>
#include<numeric>

// Solution dependencies
using std::string;
using std::vector;
using std::accumulate;

// Core: Deal with zigzag row by row
//
// Logics:
// * Define cycle is the path following zigzag pattern
//   from 0 -> max_row -> 1. Then
//     cycle_len = 2 * numRows - 2
//
// In kth cycle(0 based):
// 1. for every row, there is s[row_num + k * cycle_len]
// 2. for 0 < row_num < numRows - 1, there is another row:
//        s[(k + 1) * cycle_len - row_num]
// Time: O(n) with few cache misses (TODO: calculate cache miss rate)
// Space: O(1)
class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows <= 1) return s;

    string zigzag;
    int cycle_len = 2 * numRows - 2;
    for (int row_num = 0; row_num < numRows; ++row_num) {
      // cycle_num: 0 -> ceil(s.size() / cycle_len)
      for (int k = 0; row_num + k < s.size(); k += cycle_len) {
        // condition 1
        zigzag += s[row_num + k];
        // condition 2
        int another_index = k + cycle_len - row_num;
        if (row_num != 0 && row_num != numRows - 1 && another_index < s.size())
          zigzag += s[another_index];
      }
    }
    return zigzag;
  }
};



// Core: By ignoring the space between zigzag pattern,
//       the only thing we have to figure out is which
//       *row* should we put the char in.
//
// Visualization:
//      A B C D E F G H I J K    rowNums = 4
//      0 1 2 3 4 5 6 7 8 9 10
//   chars zigzag:           index zigzag:
//      A G                    0 6
//      B F H         →        1 5 7
//      C E I K                2 4 8 10
//      D J                    3 9
//
// Logic: 1. going down until row_num == rowNums - 1
//        2. going up until row_num = 0
//        3. repeat the above 2 steps
// Time: O(n) but with a lot of cache misses
// Space: O(1)
class Solution2 {
 public:
  string convert(string s, int numRows) {
    if (numRows <= 1) return s;

    int step, row_num = 0;
    vector<string> zigzag(numRows, "");
    for (int i = 0; i < s.size(); ++i) {
      zigzag[row_num] += s[i];
      // go down
      if (row_num == 0) step = 1;
      // go up
      if (row_num == numRows - 1) step = -1;
      row_num += step;
    }

    return accumulate(zigzag.begin(), zigzag.end(), string());
  }
};
