ListNode * middleNode(ListNode * head)
{
    Node * slow = head;
    Node * fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
      slow = slow ->next;
      fast = fast->next;
    }
    return slow->data;
}