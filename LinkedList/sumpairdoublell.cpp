Node *sumpair(Node * head,int target)
{
  Node * start = head;
  Node * end = head;
  vector<pair<int,int>> ans;
  while(end->next!=NULL)
  {
    end = end->next;
  }
  while(start!=end && end->next!=start)
  {
    if(start->data+end->data==target)
    {
      ans.push_back({start->data,end->data});
      start = start->next;
      end = end->prev;
    }
    else if(start->data+end->data<target)
    {
      start = start->next;
    }
    else{
      end = end->prev;
    }
  }
  return ans;
}