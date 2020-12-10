//Ben Bartol
//ID: 2315721
//bartol@chapman.edu
//CPSC 350 - Rene German
#include <iostream>
#include "Student.h"
#include "Faculty.h"
using namespace std;

template <class T>
class TreeNode{
  private:

  public:
    int key;
    T* data;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode();
    TreeNode(T* d, int k);
    virtual ~TreeNode();
};

template <class T>
TreeNode<T>::TreeNode(){
  key = -1;
  data = T();
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T* d, int k){
  key = k;
  data = d;
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::~TreeNode(){
  delete data;
  delete left;
  delete right;
}

//BST CLASS
template <class T>
class BST{
  protected:
    TreeNode<T> *root;
    int size;

  public:
    BST();
    virtual ~BST();

    bool contains(int k); //to see if it has k
    T* find(int k); //returning k
    void insert(TreeNode<T> *node); //inserting node k

    TreeNode<T>* getSuccessor(TreeNode<T> *k); //the node to be deleted
    bool erase(int k); //deleting node k

    T* getMin();
    T* getMax();

    void printTree();
    void printRecursive(TreeNode<T> *node);

    TreeNode<T>* getRoot();
    int getSize();
    bool isEmpty();
};


template <class T>
BST<T>::BST(){
  root = NULL;
  size = 0;
}

template <class T>
BST<T>::~BST(){

}

template <class T>
bool BST<T>::contains(int k){
  if(root == NULL){
    return false;
  }

  TreeNode<T> *curr = root;

//if the current node is less than k, goes to left node, otherwise, the right node
  while(curr->key != k){
    if(k < curr->key){
      curr = curr->left;
    }else{
      curr = curr->right;
    }

    if(curr = NULL){
      return false;
    }
  }
  return true;
}

template <class T>
T* BST<T>::find(int k){
  if(root == NULL){
    return NULL;
  }
  if(contains(k)){
    TreeNode<T> *curr = root;

    while(curr->key != k){
      if(k < curr->key){
        curr = curr->left;
      }else{
        curr = curr->right;
      }

      if(curr == NULL){
        return NULL;
      }
    }
    return curr->data;
  }else{
    return NULL;
  }
}

template <class T>
void BST<T>::insert(TreeNode<T> *node){
  if(root == NULL){
    root = node;
  }else{
    TreeNode<T> *curr = root;
    TreeNode<T> *parent;


    while(true){
      parent = curr;
      if(node->key < curr->key){
        curr = curr->left;
        if(curr == NULL){
          parent->left = node;
          break;
        }
      }else{
        if(node->key > curr->key){
          curr = curr->right;
          if(curr == NULL){
            parent->right = node;
            break;
          }
        }
      }
    }
  }
  ++size;
}

template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){
  TreeNode<T> *sp = d;
  TreeNode<T> *successor = d;
  TreeNode<T> *curr = d->right;

  while(curr != NULL){
    sp = successor;
    successor = curr;
    curr = curr->left;
  }

  if(successor != d->right){
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}

template <class T>
T* BST<T>::getMin(){
  TreeNode<T> *curr = root;
   if(root == NULL){
     return NULL;
   }
   while(curr->left == NULL){
     curr = curr->left;
   }
   return curr;
}

template <class T>
T* BST<T>::getMax(){
  TreeNode<T> *curr = root;
  if(root == NULL){
    return NULL;
  }
  while(curr->right == NULL){
    curr = curr->right;
  }
  return curr;
}

template <class T>
void BST<T>::printRecursive(TreeNode<T> *node){
  if(node == NULL){
    return;
  }
  printRecursive(node->left);
  cout << node->key << endl;
  printRecursive(node->right);
}

template <class T>
void BST<T>::printTree(){
  printRecursive(root);
}

template <class T>
TreeNode<T>* BST<T>::getRoot(){
  return root;
}

template <class T>
int BST<T>::getSize(){
  return size;
}

template <class T>
bool BST<T>::isEmpty(){
  return(size == 0);
}

template <class T>
bool BST<T>::erase(int k){
  if(root == NULL){
    return false;
  }

  TreeNode<T> *curr = root;
  TreeNode<T> *parent = root;
  bool isLeft = true;
  while(curr->key != k){
    parent = curr;

    if(k < curr->key){
      isLeft = true;
      curr = curr->left;
    }else{
      isLeft = false;
      curr = curr->right;
    }

    if(curr == NULL){
      return false;
    }
  }
  //after this, we have found the node to be deleted, but there are multiple cases

  //if the node has NO children
  if(curr->left == NULL && curr->right == NULL){
    if(curr = root){
      root = NULL;
    }else if(isLeft){
      parent->left = NULL;
    }else{
      parent->right = NULL;
    }

    //node to be deleted has one LEFT child

  }else if(curr->right == NULL){
    if(curr == root){
      root = curr->right;
    }else if(isLeft){
      parent->left = curr->left;
    }else{
      parent->right = curr->right;
    }

    //node to be deleted has one RIGHT child
  }else if(curr->left == NULL){
    if(curr == root){
      root = curr->left;
    }else if(isLeft){
      parent->left = curr->right;
    }else{
      parent->right = curr->right;
    }

    //node to be deleted has TWO children
  }else{
    TreeNode<T> *successor = getSuccessor(curr);

    if(curr == root){
      root = successor;
    }else if(isLeft){
      parent->left = successor;
    }else{
      parent->right = successor;
    }
    successor->left = curr->left;
  }
  --size;
  return true;
}
