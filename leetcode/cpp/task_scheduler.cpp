// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(1)

// Solution dependencies
#include<algorithm>
#include<functional>
#include<string>
#include<queue>
#include<vector>

// Solution dependencies
using std::begin;
using std::end;
using std::greater;
using std::max;
using std::sort;
using std::string;
using std::vector;
using std::priority_queue;

// Core:
// Greedy Arrangement
// E.g AAABBBCCD 2 -> AB x AB x AB  this or length
// Time: O(n)
// Space: O(1)
class Solution {
 public:
  int leastInterval(const vector<char>& tasks, int n) {
    int counter[26] = {0};
    for (const auto& t : tasks)  ++counter[t - 'A'];

    // descending order
    sort(begin(counter), end(counter), greater<int>());

    int greedy_len = (counter[0] - 1) * (n + 1);
    for (int i = 0; i < 26 && counter[i] == counter[0]; ++i) ++greedy_len;

    return max(greedy_len, static_cast<int>(tasks.size()));
  }
};

// Core: priority queue to dynamically sort task by its frequencies
//       in each round we take tasks by frequencies
// Time: O(n)
// Space: O(n)
class Solution2 {
 public:
  int leastInterval(const vector<char>& tasks, int n) {
    int counter[26] = {0};
    for (const auto& t : tasks) ++counter[t - 'A'];

    priority_queue<int> task_frequency_queue;
    for (const auto& count : counter) {
      if (count != 0) task_frequency_queue.push(count);
    }

    int total_time = 0;
    while (!task_frequency_queue.empty()) {
      vector<int> selected_frequency;
      int time = 0;
      for (int i = 0; i < n + 1; ++i) {
        if (!task_frequency_queue.empty()) {
          int max_frequency = task_frequency_queue.top();
          task_frequency_queue.pop();
          selected_frequency.emplace_back(max_frequency);
          ++time;
        }
      }
      for (auto &f : selected_frequency) {
        if (--f != 0) task_frequency_queue.push(f);
      }
      total_time += (task_frequency_queue.empty() ? time : n + 1);
    }
    return total_time;
  }
};
