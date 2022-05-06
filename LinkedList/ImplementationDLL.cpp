class Node{
  public:
  int val;
  Node* prev;
  Node* next;
  Node(int val){
    this->val=val;
    prev = nullptr;
    next = nullptr;
  }
};
class MyLinkedList{
  public:
  Node *head;
  Node *tail;
  MyLinkedList(){
    head = nullptr;
    tail = nullptr;
  }

  int get(int index){
    if( head == NULL){
    return -1;
    }
    Node *temp = head;
    int count = 0;
    while(temp!=NULL){
      temp = temo->next;
      count++;
    }
    if(index>=count)
    return -1;
    temp = head;
    while(head != NULL && index>0){
      temp = temp->next;
      index--;
    }
    return temp->val;
  }

  void addAtHead(int val){
    Node *newNode = new Node(val);
    if(head == NULL){
    head = newNode;
    tail = newNode;
  }
  else{
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
  }

void addAtTail(int val){
  Node *temp = head;
  if(head == NULL){
    Node * newNode = new Node(val);
    head = newNode;
    tail = newNode;
    return;
  }
  while(temp->next!=NULL){
    temp = temp->next;
  }
  Node * newNode = new Node(val);
  temp->next = newNode;
  newNode->prev = temp;
  tail = newNode;
}
void addAtIndex(int index,int val){
  Node* temp = head;
  int count = 0;
  while(temp != NULL){
    temp = temp->next;
    count++;
  }
  if(index>count)return;
  if(index==0){
    addAtHead(val);
    return;
  }else if(count == index){
    addAtTail(val);
    return;
  }
  else{
    temp = head;
    while(temp != NULL && index>0){
      temp = temp->next;
      index--;
    }
    Node* newNode = new Node(val);
    Node *temp2 = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
    newNode->prev = temp2;
    newNode->next = temp;
  }
}
void deleteAtIndex(int index){
  Node *temp = head;
  int count = 0;
  while(temp != NULL){
    temp = temp->next;
    count++;
  }
  if(index>=count)return;
  if(count==1 && index == 0){
    head = NULL;
    return;
  }else if(count-1 == index){
    tail = tail->prev;
    tail->next = NULL;
    return;
  }else{
    if(index==0){
      head->next->prev = NULL;
      head = head->next;
      return ;
    }
    temp head;
    while(temp!=NULL && index>0){
      temp = temp->next;
      index--;

    }
    Node* temp2 = temp->next;
    temp->prev->next = temp2;
    temp->next->prec = temp->prev;
  }
}
};