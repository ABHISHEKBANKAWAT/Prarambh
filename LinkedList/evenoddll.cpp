ListNode *oddEvenList(ListNode *head)
{
  Node * oddh=NULL,*oddt=NULL,*evenh=NULL,*event=NULL;
  int count=0;
  
  while(head!=NULL)
  {
    if(count%2==0)
    {
      if(evenh==NULL)
      {
        evenh = head;
        event = head;
        head = head->next;
      }else{
        event->next = head;
        event = event->next;
        head  = head->next;
      }
    }
    else{
      if (oddh == NULL)
      {
        oddh = head;
        oddt = head;
        head = head->next;
      }
      else
      {
        oddt->next = head;
        oddt = event->next;
        head = head->next;
      }
    }
  }
  if(oddh==NULL)
  {
    return evenh;
  }
  if(evenh==NULL)
  {
    return oddh;
  }
  event->next = NULL;
  oddt->next = evenh;
  return oddh;
}