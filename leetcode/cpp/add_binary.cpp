// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(1)

// Solution dependencies
#include<algorithm>
#include<string>
#include<vector>

using std::reverse;
using std::string;
using std::vector;

class Solution {
 public:
  string addBinary(string a, string b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry_flag = 0;
    string binary_sum;
    while (i >= 0 || j >= 0 || carry_flag) {
      int sum = 0;
      if (i >= 0 && a[i] == '1') sum += 1;
      if (j >= 0 && b[j] == '1') sum += 1;
      sum += carry_flag;
      carry_flag = sum / 2;
      char remainder = (sum % 2 == 0 ? '0' : '1');
      binary_sum.push_back(remainder);
      --i;
      --j;
    }
    reverse(binary_sum.begin(), binary_sum.end());
    return binary_sum;
  }
};
