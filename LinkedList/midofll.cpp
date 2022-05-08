ListNode * midofList(ListNode * head){
  ListNode * fast = head, *slow = head;
  while(fast!=NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}