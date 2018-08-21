// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(number of digits)
// Best solution space: O(1)

// Solution dependencies
#include<string>
#include<vector>

// Solution dependencies
using std::string;
using std::vector;

// Core:
// Implementation with 3 digits as a pack
const string kThousands[] = {"", "Thousand", "Million", "Billion"}; // NOLINT(*)
const string kTens[] = { // NOLINT(*)
  "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
  "Eighty", "Ninety"
};
const string kLessThan20[] = { // NOLINT(*)
  "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
  "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
  "Sixteen", "Seventeen", "Eighteen", "Nineteen"
};
const string kZero = "Zero"; // NOLINT(*)

class Solution {
 public:
  string numberToWords(int num) {
    if (num == 0) return kZero;

    string words;
    int i = 0;
    while (num != 0) {
      int r = num % 1000;
      if (r != 0)
        words = LessThousandToWords(r) + kThousands[i] + " " + words;
      ++i;
      num /= 1000;
    }
    // TODO(hitlye): check if we could use erase here because of only one space
    string trimed_words = words.substr(0, words.find_last_not_of(' ') + 1);
    return trimed_words;
  }

  string LessThousandToWords(int num) {
    if (num == 0) return "";
    if (num < 20) return kLessThan20[num] + " ";
    if (num < 100) return kTens[num / 10] + " " + LessThousandToWords(num % 10);
    return kLessThan20[num / 100] + " Hundred " +  LessThousandToWords(num % 100); // NOLINT(*)
  }
};
