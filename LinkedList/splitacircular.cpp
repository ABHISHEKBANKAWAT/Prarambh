Node * spliacircular(Node * head,Node *head1_ref,Node * head2_ref)
{
  Node * slow = head;
  Node * fast = slow->next;
  while(fast!=head && fast->next!=head)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  *head1_ref = head;
  *head2_ref = slow->next;
  slow->next = head1_ref;
  Node * current = *head2_ref;
  while(current->next!=head)
  {
    current=current->next;
  }
  current->next = *head2_ref
}