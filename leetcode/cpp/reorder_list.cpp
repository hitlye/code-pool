// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n)
// Best solution space: O(1)

// Core:
// 1. fast-slow double pointer to find the mid.
// 2. reverse the last half of linked list
// 3. merge two linked list into one
// Time: O(n)
// Space: O(1)
struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  void reorderList(ListNode* head) {
    // empty or one node list
    if (!head || !head->next) return;

    // find mid of the given linked list
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    // reverse the last half of given linked list
    ListNode *half_head = slow->next;
    slow->next = nullptr;
    ListNode *prev = nullptr;
    while (half_head->next != nullptr) {
      ListNode *next = half_head->next;
      half_head->next = prev;
      prev = half_head;
      half_head = next;
    }
    half_head->next = prev;

    // merge the new two half linked list
    ListNode *pNode = head, *qNode = half_head;
    while (pNode) {
      ListNode *node = pNode->next;
      pNode->next = qNode;
      pNode = qNode;
      qNode = node;
    }
  }
};
