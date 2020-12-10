//Ben Bartol
//ID: 2315721
//bartol@chapman.edu
//CPSC 350 - Rene German
#include <iostream>
#include "ListNode.h"
using namespace std;

template <class T>
class DoublyLinkedList{
  private:

  public:
    unsigned int size;
    ListNode<T> *front;
    ListNode<T> *back;

    DoublyLinkedList(); //Constructor
    ~DoublyLinkedList(); //Destructor

    void insertBack(T data);
    T removeFront();
    T getFront();

    void printList();
    void deletePos(int pos);

    bool isEmpty();
    unsigned int getSize();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d){
  ListNode<T> *node = new ListNode<T>(d);


  if(size = 0){
    front = node;
  }else{
    back->next = node;
    node->prev = back;
  }

  back = node;
  ++size;
}

template <class T>
T DoublyLinkedList<T>::removeFront(){
  if(!isEmpty()){
    ListNode<T> *node = front;

    //if the only node in List
    if(front->next == NULL){
      front = NULL;
      back = NULL;
    }else{ //not the only node
      front->next->prev = NULL;
      front = front->next;
    }
    T temp = node->data;
    delete node;
    --size;
    return temp;
  }else{
    return T();
  }
}

template <class T>
T DoublyLinkedList<T>::getFront(){
  return front->data;
}

template <class T>
void DoublyLinkedList<T>::printList(){
  ListNode<T> *curr = front;

  while(true){
    if(curr->next == NULL){
      break;
    }

    cout << curr->data << endl;
    curr = curr->next;
  }
}

template <class T>
void DoublyLinkedList<T>::deletePos(int pos){
  int indx = 0;
  ListNode<T> *curr = front;
  ListNode<T> *prev = front;

  while(indx != pos){
    prev = curr;
    curr = curr->next;
    ++indx;
  }

  prev->next = curr->next;
  curr->next->prev = prev;
  curr->next = NULL;
  curr->data = NULL;
  curr->prev = NULL;

  --size;
  delete curr;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty(){
  return(size == 0);
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize(){
  return size;
}
