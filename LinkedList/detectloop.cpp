boolean detectloop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
      if(slow==fast)
      {
        return true;
      }
      else
      {
        slow = slow->next;
        fast = fast-next->next;
      }
    }
    return false;
}