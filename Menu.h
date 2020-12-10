//Ben Bartol
//ID: 2315721
//bartol@chapman.edu
//CPSC 350 - Rene German
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <sys/stat.h>
#include "BST.h"
using namespace std;

class Menu{
  private:

  public:
    BST<Student> masterStudent;
    BST<Faculty> masterFaculty;

    Menu();
    ~Menu();

    void readFile();
    void writeFile();

    void printMS(TreeNode<Student> *s);
    void printMF(TreeNode<Faculty> *f);

    void outputMS(TreeNode<Student> *s, string student);
    void outputMF(TreeNode<Faculty> *f, string faculty);

    TreeNode<Student>* getMSroot();
    TreeNode<Faculty>* getMFroot();

    void printMenu();
    void printAllStudents();
    void printAllFaculty();
    void printStudent();
    void printFaculty();
    void printAdvisor();
    void printAdvisee();

    void addStudent();
    void removeStudent();
    void addFaculty();
    void removeFaculty();
    void changeAdvisor();
    void removeAdvisee();

    void rollback();
    void exit();
};
