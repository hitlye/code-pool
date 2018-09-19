// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(xx)
// Best solution space: O(xx)

// double linked list + hash_map

struct Node {
  int key;
  int value;
  Node *prev;
  Node *next;
  explicit Node(int k, int v) {
    key = k;
    value = v;
    prev = nullptr;
    next = nullptr;
  }
};

typedef Node *pNode;

class LRUCache {
 public:
  explicit LRUCache(int capacity) {
    capacity_ = capacity;
    head_ = new Node(-1, -1);
    tail_ = new Node(-1, -1);
    head_->next = tail_;
    tail_->prev = head_;
  }

  int get(int key) {
    const auto found = node_addr_table_.find(key);
    if (found == node_addr_table_.end()) return -1;
    // update node
    pNode out_node = found->second;
    out_node->prev->next = out_node->next;
    out_node->next->prev = out_node->prev;

    // insert into end of list
    tail_->prev->next = out_node;
    out_node->prev = tail_->prev;
    tail_->prev = out_node;
    out_node->next = tail_;
    return out_node->value;
  }

  void put(int key, int value) {
    // check capacity
    if (node_addr_table_.size() == capacity_ &&
        node_addr_table_.find(key) == node_addr_table_.end()) {
      // select least recent used node to be invalidated,
      // in our implementation, it must be the first node in our linked list.
      pNode in_node = new Node(key, value);
      pNode out_node = head_->next;
      // 1. remove from node table
      node_addr_table_.erase(out_node->key);
      // 2. remove from double linked list
      head_->next = out_node->next;
      out_node->next->prev = head_;
      // 3. put new node in the end of list
      tail_->prev->next = in_node;
      in_node->prev = tail_->prev;
      tail_->prev = in_node;
      in_node->next = tail_;
      // 4. put into map
      node_addr_table_[key] = in_node;
      // 5. release mem of out_node;
      delete out_node;
    } else {
      // update exist node or insert new node
      if (node_addr_table_.find(key) != node_addr_table_.end()) {
        // delete exist one
        pNode out_node = node_addr_table_[key];
        out_node->prev->next = out_node->next;
        out_node->next->prev = out_node->prev;
        delete out_node;
        node_addr_table_.erase(key);
      }
      pNode in_node = new Node(key, value);
      // insert into end of list
      tail_->prev->next = in_node;
      in_node->prev = tail_->prev;
      tail_->prev = in_node;
      in_node->next = tail_;
      // also in map
      node_addr_table_[key] = in_node;
    }
  }

 private:
  unordered_map<int, pNode> node_addr_table_;
  pNode head_;
  pNode tail_;
  int capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
