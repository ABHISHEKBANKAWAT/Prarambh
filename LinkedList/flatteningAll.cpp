Node *flatten(Node *root)
{
  // Your code here
  if (root == NULL)
    return NULL;
  if (root->next == NULL)
    return root;
  return mergelist(root, flatten(root->next));
}
Node *mergelist(Node *head1, Node *head2)
{
  Node *finalhead = NULL;
  Node *finaltail = NULL;
  while (head1 != NULL && head2 != NULL)
  {
    if (finalhead == NULL && finaltail == NULL)
    {
      if (head1->data < head2->data)
      {
        finalhead = head1;
        finaltail = head1;
        head1 = head1->bottom;
      }
      else
      {
        finalhead = head2;
        finaltail = head2;
        head2 = head2->bottom;
      }
    }
    else
    {
      if (head1->data < head2->data)
      {
        finaltail->bottom = head1;
        finaltail = finaltail->bottom;
        head1 = head1->bottom;
      }
      else
      {
        finaltail->bottom = head2;
        finaltail = finaltail->bottom;
        head2 = head2->bottom;
      }
    }
  }
  if (head1 != NULL)
  {
    finaltail->bottom = head1;
  }
  if (head2 != NULL)
  {
    finaltail->bottom = head2;
  }
  return finalhead;
}