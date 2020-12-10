//Ben Bartol
//ID: 2315721
//bartol@chapman.edu
//CPSC 350 - Rene German
#include <iostream>
#ifndef included
#define included
using namespace std;

class Member{
  public:
    int id;
    string name;
    string level;

    Member();
    ~Member();

    int getID();
    void setID(int value);

    string getName();
    string getLevel();

};
#endif
