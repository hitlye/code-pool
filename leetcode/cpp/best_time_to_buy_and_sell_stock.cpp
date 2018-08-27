// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(1)

// Solution dependencies
#include<vector>

using std::vector;

class Solution {
 public:
  int maxProfit(const vector<int>& prices) {
    int max_profit = 0;
    int current_min = INT_MAX;
    for (size_t i = 0; i < prices.size(); ++i) {
      if (prices[i] < current_min) {
        current_min = prices[i];
        continue;
      }
      int profit = prices[i] - current_min;
      if (max_profit < profit) max_profit = profit;
    }
    return max_profit;
  }
};
