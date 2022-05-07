void deletenode(ListNode * node){
  if(node->next==NULL)
  delete node;
  node->val = node->next->val;
  node *temp = node->next;
  node->next = node->next->next;
  delete temp;
}