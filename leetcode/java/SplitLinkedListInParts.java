class SplitLinkedListInParts {
  public ListNode[] splitListToParts(ListNode root, int k) {
    ListNode[] parts = new ListNode[k];
    int[] partLens = new int[k];
    int len = 0;
    ListNode rootForCount = root;

    while (rootForCount != null) {
      len++;
      rootForCount = rootForCount.next;
    }

    int basic = len / k;
    int remnant = len % k;
    int i = 0;
    for (; i < remnant; i++) {
      partLens[i] = basic + 1;
    }
    for (; i < k; i++) {
      partLens[i] = basic;
    }

    for (i = 0; i < k; i++) {
      if (partLens[i] == 0)
        break;

      parts[i] = root;
      int idx = 0;
      while (idx++ < partLens[i] - 1) {
        root = root.next;
      }

      ListNode nodeNext = root.next;
      root.next = null;
      root = nodeNext;
    }

    return parts;
  }
}
