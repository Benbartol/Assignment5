//Ben Bartol
//ID: 2315721
//bartol@chapman.edu
//CPSC 350 - Rene German

#include <iostream>
#include <stack>
#include <string>
using namespace std;

template <class T>

class GenStack{

  private:


  public:
    GenStack();//default constructor
    GenStack(int maxSize);//overloaded constructor
    ~GenStack();//destructor

    //core functions
    void push(T data);//interset an item
    T* pop();//remove an element
    T* peek();//AKA top

    //aux/helper functions
    int isEmpty();
    int isFull();
    void increaseSize();

    int top;
    int max;

    T *myArray;//the memory address of the first block
    T *tempArray;
};

//Constructor
template <class T>
GenStack<T>::GenStack(int maxSize){
  myArray = new T[maxSize];
  max = maxSize;
  top = -1;
  tempArray = new T[max];
}

//Destructor
template <class T>
GenStack<T>::~GenStack(){
  delete []myArray;
  delete []tempArray;

  cout << "Stack has been erased" << endl;
}

template <class T>
void GenStack<T>::push(T data){
  if (isFull() == 1){
    increaseSize();
    push(data);
  }else{
    myArray[++top] = data;
  }
}

template <class T>
T* GenStack<T>::pop(){
  if(isEmpty() == 1){
    cout << "Error: stack is empty" << endl;
    return 0;
  }else{
    return myArray[top--];
  }
}

template <class T>
T* GenStack<T>::peek(){
  if(top == -1){
    return 0;
  }else{
    return myArray[top];
  }
}

template <class T>
int GenStack<T>::isEmpty(){
  return (top == -1);
}

template <class T>
int GenStack<T>::isFull(){
  return (top == -1);
}

template <class T>
void GenStack<T>::increaseSize(){
  tempArray = new T[max];

  for(int i = top; i > -1; --i){
    tempArray[i] = myArray[i];
  }

  max += 1;
  myArray = new T[max];
  for(int i = top; i > -1; --i){
    tempArray[i] = myArray[i];
  }
}
