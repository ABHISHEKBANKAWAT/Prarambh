void removeLoop(Node *head)
{
  Node *slow = head;
  Node *fast = head;
  slow = slow->next;
  fast = fast->next->next;
  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      break;
  }
  if (slow == fast)
  {
    fast = head;
    if (slow == fast)
    {
      while (slow->next != fast)
        slow = slow->next;
    }
    else
    {
      while (slow->next != fast->next)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }
    slow->next = NULL;
  }
}