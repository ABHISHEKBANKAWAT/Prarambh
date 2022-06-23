// FROM SORTED LINKEDLIST

ListNode * removeDuplicate(ListNode * head)
{
  Node * current = head;
  while(current->next!=NULL){
    if(current->data==current->next->data)
    {
      current->next = current->next->next;
    }
    else
    {
      current = current->next;
    }
  }
  return head;
}

// FROM UNSORTED LINKEDLIST
ListNode *removeDuplicate(ListNode *head)
{
  unordered_set<int> seen;
  Node * curr = head;
  Node * prev = NULL;
  while(curr!=NULL)
  {
    if(seen.find(curr->data)!=seen.end()){
      prev->next = curr->next;
      delete(curr);
    }
    else
    {
      seen.insert(curr->data);
      prev = curr;
    }
    curr = prev->next;
  }
  return head;
}
