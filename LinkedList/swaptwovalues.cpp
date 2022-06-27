ListNode * swaptwoNodes(Node * head,int x,int y)
{
  if(x==y)
  return;
  Node *prevX=NULL,*currX=NULL;
  while(currX && currX->data!=x)
  {
    prevX=currX;
    currX = currX->next;
  }
  Node *prevY=NULL , *prevY=NULL;
  while(currY && currY->data!=y)
  {
    prevY = currY;
    currY = currY->next;
  }
  if(currX==NULL && currY==NULL)
  return;
  if(prevX!=NULL)
  {
    prevX->next = currY;
  }else{
    *head_ref = currY;
  }
  if(prevY!=NULL)
  {
    prevY->next = currX;
  }
  else{
    *head_ref = currX;
  }
  Node * temp = currY->next;
  currY->next = currX->next;
  currX->next = temp;
  
}