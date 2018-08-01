// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(n)

// Solution dependencies
#include<cassert>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(nullptr) {}
};

// Core: From head to tail, add nodes one by none
//      6 -> 2 -> 4
//      4 -> 5 -> 6
//      ↓    ↓    ↓
//      0 -> 1+7 -> 0 -> 1
// Trick: Use a dummy node to avoid dealing with head seperately
// Corner cases:
//    1. Do not ingore the last carry_flag.
// Time: O(n)
// Space: O(n)
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // Assumption: both l1 and l2 are not null
    assert(l1 != nullptr && l2 != nullptr);

    ListNode dummy{0}, *tail = &dummy;
    int carry_flag = 0;
    while (l1 || l2 || carry_flag) {
      int sum = carry_flag;
      if (l1) {sum += l1->val; l1 = l1->next;}
      if (l2) {sum += l2->val; l2 = l2->next;}

      // update carry_flag
      carry_flag = sum / 10;
      tail->next = new ListNode(sum % 10);
      tail = tail->next;
    }
    return dummy.next;
  }
};
