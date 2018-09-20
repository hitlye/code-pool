// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(1)

class Solution {
 public:
  string getHint(string secret, string guess) {
    vector<int> secret_num_table(10, 0);
    vector<int> guess_num_table(10, 0);

    int a_counter = 0;
    for (int i = 0; i < secret.size() && i < guess.size(); ++i) {
      if (secret[i] == guess[i]) {
        ++a_counter;
        continue;
      }
      ++secret_num_table[secret[i] - '0'];
      ++guess_num_table[guess[i] - '0'];
    }

    int b_counter = 0;
    for (int i = 0; i < secret_num_table.size(); ++i) {
      if (secret_num_table[i] != 0 && guess_num_table[i]) {
        b_counter += min(secret_num_table[i], guess_num_table[i]);
      }
    }

    return to_string(a_counter) + "A" + to_string(b_counter) + "B";
  }
};
