class OddEvenLinkedList {
  public ListNode oddEvenList(ListNode head) {
    if (head == null) {
      return null;
    }

    ListNode oddHead = head;
    ListNode evenHead = head.next;
    ListNode oddNode = head;
    ListNode evenNode = head.next;
    while (evenNode != null && evenNode.next != null) {
      oddNode.next = evenNode.next;
      evenNode.next = evenNode.next.next;
      oddNode = oddNode.next;
      evenNode = evenNode.next;
    }
    oddNode.next = evenHead;

    return oddHead;
  }
}

class ListNode {
  int val;
  ListNode next;
  ListNode(int x) { val = x; }
}