ListNode * addtwo(ListNode * first,ListNode *second)
{
  if(length(first)<length(second)){
    Node * temp = first;
    first = second;
    second = temp;
  }
  Node * big = reverse(first);
  Node * big1 = big;
  Node * small = reverse(second);
  Node * small1 = small;
  Node * prev = NULL;
  int carry = 0;
  while(big1!=NULL or small1!=NULL)
  { int bigdata=0,smalldata=0;
    if(big1==NULL){
      bigdata=0;
    }
    else
    {
      bigdata = big1->data;
    }
    if(small1==NULL)
    {
      smalldata=0;
    }else{
      smalldata=small1->data;
    }
    int sum = bigdata+smalldata+carry;
    carry = sum/10;
    big1->data = sum%10;
    prev = big1;
    big1 = big1->next;
    if(small1!=NULL)
    {
      small1 = small1->next;
    }
  }
  if(carry==1)
  {
    Node * newNode = new Node(1);
    prev->next = newNode;
  }
  return reverse(big);
}