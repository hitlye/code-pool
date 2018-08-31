// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(nlogn)
// Best solution space: O(1)

// Solution dependencies
#include<cmath>
#include<string>
#include<vector>

using std::max;
using std::string;
using std::vector;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
  vector<Interval> merge(vector<Interval>& intervals) {
    if (intervals.empty()) return vector<Interval>();

    // inplace sort by start
    sort(intervals.begin(), intervals.end(),
         [](const Interval &a, const Interval &b) -> bool {
           return a.start < b.start;
         });

    // inserting into new array
    vector<Interval> merged_intervals = {intervals[0]};
    for (const auto &interval : intervals) {
      int &last_interval_end = merged_intervals.back().end;
      if (interval.start <= last_interval_end) {
        last_interval_end = max(last_interval_end, interval.end);
      } else {
        merged_intervals.emplace_back(interval);
      }
    }
    return merged_intervals;
  }
};
