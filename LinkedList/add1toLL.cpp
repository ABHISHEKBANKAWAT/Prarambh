ListNode *  add1toLL(ListNode * head)
{
  Node * newhead = reverse(head);
  Node * curr = newhead,curr1 = newhead;
  Node * prev = NULL;
  int carry = 0;

  while(curr!=NULL)
  {
    int sum = 0;
    if(prev==NULL)
    {
      sum=current->data+1;
    }else{
      sum = current->data+carry;
    }
    carry = sum/10;
    curr->data = sum%10;
    prev = current;
    current=current->next;
  }
  if(carry==1)
  {
    Node* newNode = new Node(1);
    prev->next = newNode;
  }
  return reverse(curr1);
} 
Node * reverse(Node *head)
{
  if (head == NULL)
  {
    return 0;
  }
  ListNode *prev = NULL;
  ListNode *curr = head;
  ListNode *ahead = head->next;

  while (curr->next != NULL)
  {
    curr->next = prev;
    prev = curr;
    curr = ahead;
    ahead = ahead->next;
  }
  curr->next = prev;
  return curr;
}
