#include<bits/stdc++.h>
using namespace std;
class Node{
public:
  int data;
  Node *next;
  Node(int d){
    data = d;
    next = NULL;
  }
};
void printList(Node *head){
  Node * temp = head;
    while(temp!=NULL){
      cout<<temp->data<<",";
      temp=temp->next;
    }
}
Node *addAtHead(Node * head){
  Node * newhead = new Node(50);
  newhead->next = head;
  return newhead;
}

void addAfter(Node *head,int val){
  Node * newNode =new Node(4);
  Node *temp = head;
  while(temp->data!=val){
    temp=temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
}
void addTail(Node *head){
  Node * newNode = new Node(6);
  Node * temp = head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next = newNode;
}
Node *deletefromStart(Node * head){
  head = head->next;
  return head;
}
Node *deletefromEnd(Node * head){
  Node * temp = head;
  while(temp->next->next!=NULL){
    temp  = temp->next;
  }
  temp->next = NULL;
}
Node *deleteAny(Node* head,int val){
  if(head->data==val){
    return head->next;
  }
  Node * temp = head;
  Node * prev = NULL;
  while(temp->data!=val){
    prev=head;
    temp=temp->next;
  }
  prev->next = temp->next;
  return head;
}
int main(){ 
  Node* head =new Node(1);
  Node* second = new Node(2);
  Node* third = new Node(3);
  head->next = second;
  second->next = third;
  third->next = NULL;
  head = addAtHead(head);
  addAfter(head,2);
  addTail(head);
  head = deletefromStart(head);
  deletefromEnd(head);
  deleteAny(head,2);
  printList(head);  

  return 0;
}