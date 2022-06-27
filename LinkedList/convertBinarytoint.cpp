int getDecimalValue(ListNode *head)
{
  ListNode *temp = reverse(head);
  int x, total = 0, i = 0;
  while (temp != NULL)
  {
    x = temp->val;
    total = total + pow(2, i) * x;
    i++;
    temp = temp->next;
  }
  return total;
}
ListNode *reverse(ListNode *head)
{
  ListNode *current = head, *prev = NULL, *next = NULL;
  while (curr != NULL)
  {
    next = curr->next;
    current->next = prev;
    prev = curr;
    current = nextt;
  }
  head=prev;
  return head;
}