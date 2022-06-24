Listnode * intersectionofY(Node * head1,Node* head2)
{
  Node * temp1= head1;
  Node * temp2 = head2;
  while(1)
  {
    if(temp1==temp2)
    {
      return temp1->data;
    }
    if(temp1==NULL)
    {
      temp1=head1;
    }else{
      temp1 = temp1->next;
    }
    if(temp2==NULL)
    {
      temp2=head1;
    }else{
      temp2=temp2->next;
    }
  }
  return 0;
}