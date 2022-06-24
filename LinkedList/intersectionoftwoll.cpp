listNode * intersectionofLl(Listnode * head1,ListNdoe * head2)
{
    Node * new1 = head1;
    Node * new2 = head2;
    Node * dummy = new Node(1);
    Node * current = dummy;
    while(new!=NULL && new2!=NULL)
    {
      if(new1->data < new2->data)
      {
        new1 = new1->next;
      }
      else if(new2->data<new1->data)
      {
        new2 = new2->data;
      }
      else if(new1->data==new2->data)
      {
          Node * newNode = new Node(new1->data);
          current->next = newNode;
          current = current->next;
          new1 = new1->next;
          new2 = new2->next;
      }
    }
}