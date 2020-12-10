//Ben Bartol
//ID: 2315721
//bartol@chapman.edu
//CPSC 350 - Rene German#include <iostream>
#include "ListNode.h"
using namespace std;

template <class T>
class GenQueue{
  private:

  public:
    unsigned int numElements;
    ListNode<T> *front;
    ListNode<T> *back;

    GenQueue();
    ~GenQueue();

    void enqueue(T d);
    T dequeue();

    T xFront();
    T xBack();

    void printQ();
    bool isEmpty();
    unsigned int getSize();

};

template <class T>
GenQueue<T>::GenQueue(){
  numElements = 0;
  front = NULL;
  back = NULL;
}

template <class T>
GenQueue<T>::~GenQueue(){

}

template <class T>
void GenQueue<T>::enqueue(T d){
  ListNode<T> *node = new ListNode<T>(d);

  if(numElements == 0){
    front = node;
  }else{
    back->next = node;
    node->prev = back;
  }

  back = node;
  ++numElements;
}

template <class T>
T GenQueue<T>::dequeue(){
  if(!isEmpty()){
    ListNode<T> *node = front;

    T temp = node->data;

    if(front->nect == NULL){
      front = NULL;
      back = NULL;
    }else{
      front->next->prev = NULL;
      front = front->next;
    }

    delete node;
    --numElements;
    return temp;
  }else{
    return T();
  }
}

template <class T>
T GenQueue<T>::xFront(){
  return front->data;
}

template <class T>
T GenQueue<T>::xBack(){
  return back->data;
}

template <class T>
void GenQueue<T>::printQ(){
  ListNode<T> *curr = front;

  while(true){
    if(curr != NULL){
      cout << curr->data << endl;
      curr = curr->next;
    }else{
      break;
    }
  }
}

template <class T>
bool GenQueue<T>::isEmpty(){
  return (numElements == 0);
}

template <class T>
unsigned int GenQueue<T>::getSize(){
  return numElements;
}
