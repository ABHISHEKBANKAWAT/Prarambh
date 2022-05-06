/*
linked list is designed using nodes and in singly-linked list we have two attributes : val(value of current node) and next(pointer to next node) and in doubly linked list we use one more attribute prev to store address of previous Node.
Implement these functions in your linked list class:

get(index) :  Get the value of the index-th node in the linked list. If the index is invalid, return -1.
addAtHead(val) :  Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
addAtTail(val) : Append a node of value val to the last element of the linked list.
addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.

Example:
Input:
["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
[[],[1],[3],[1,2],[1],[1],[1]]
Output:
[null,null,null,null,2,null,3]
Explanation:
MyLinkedList linkedList = new MyLinkedList(); // Initialize empty LinkedList
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3

Constraints:
0 <= index,val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail,  addAtIndex and deleteAtIndex.
*/
class MyLinkedList{
  private:
    struct Node{
      int val;
      Node * next;
      Node(int x): val(x);next(NULL){};
    };
    Node *head;
    int size;
  public:

    /*initialize your data Structure here*/
    MyLinkedList(){
      head = NULL;
      size = 0;
    }
    /*get the value of index node in the linked list */
    int get(int index){
      if(size<=index){
        return -1;
      }
      Node *temp = head;
      for(int i = 0 ; i < index ; i++){
        temp = temp->next;
      }
      return temp->val;
    }
    /*Add a node of value val before the first element of the linkedlist */
    void addAtHead(int val){
      Node *prevHead = head;
      head = new Node(val);
      head->next = prevHead;
      size++;
    }
    /*Append a node at the end of the linked list*/
    void addAtTail(int val){
      Node *last = new Node(val);
      if(head == NULL){
        head = last;
      }
      else{
        Node *temp = head;
        while(temp->next != NULL){temp = temp->next;}
        temp-next = last;
      }
      size++;
    }
    /*Add a Node at any given Index*/
    void addAtIndex(int index,int val){
      if(size<index){return ;}
      Node * toAdd = new Node(val);
      if(index==0){
        addAtHead(val);
      }else{
        Node *temp = head;
        for(int i = 0 ; i < index-1;i++){
          temp = temp->next;
        }
          if(temp->next != NULL){
            toAdd->next = temp->next;
          }
          temp->next = toAdd;
          size++;
      }
    }
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index){
    if(size<=index){
        return;
      }
    if(index==0){
        head = head->next;
      }
    else{
      Node* temp = head;
      for(int i = 0 ; i<index-1;i++){temp=temp->next;}
      temp->next = temp->next->next;
      }
      size--;
    }
};
