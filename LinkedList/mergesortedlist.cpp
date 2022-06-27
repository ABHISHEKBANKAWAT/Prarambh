ListNode * mergetwoLL(Node * head1 , Node* head2)
{
  Node* finalhead = NULL;
  Node * finaltail = NULL;
  while(head1!=NULL && head2!=NULL)
  {
    if(finalhead==NULL && finaltail==NULL)
    {
      if(head1->data<head2->data)
      {
        finalhead = head1;
        finaltail = head2;
        head1 = head1->next;
      }
      else{
        finalhead = head2;
        finaltail = head1;
        head2 = head2->next;
      }
    }
    if(head1->data<head2->data)
    {
      finaltail->next = head1;
      finaltail = finaltail->next;
      head1= head1->next;
    }else{
      finaltail->next = head2;
      finaltail = finaltail->next;
      head2 = head2->next;
    }
  }
  if(head1!=NULL)
  {
    finaltail->next = head1;
    head1 = head1->next;
  }
  else if(head2!=NULL)
  {
    finaltail->next = head2;
    head2 = head2->next;
  }
  return finalhead;
}