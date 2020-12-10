//Ben Bartol
//ID: 2315721
//bartol@chapman.edu
//CPSC 350 - Rene German
#include <iostream>
#include "DoublyLinkedList.h"
#include "Member.h"
using namespace std;

class Faculty : public Member{
  private:

  public:
    string department;
    unsigned int numAdvisee;
    unsigned int maxSize;

    int *adviseeArray;

    Faculty();
    ~Faculty();
    Faculty(int xID, string xName, string xLevel, string xDepartment);

    void printFaculty();
    void printAdvisee();
    string getDepartment();

    int getAdviseeID();
    void addAdvisee(int xID);
    bool removeAdvisee(int xAdviseeID);
    int getSizeArray();

    bool operator == (const Faculty &f){
      return(this->id == f.id);
    }
    bool operator != (const Faculty &f){
      return(this->id != f.id);
    }
    bool operator <= (const Faculty &f){
      return(this->id <= f.id);
    }
    bool operator >= (const Faculty &f){
      return(this->id >= f.id);
    }
    bool operator < (const Faculty &f){
      return(this->id < f.id);
    }
    bool operator > (const Faculty &f){
      return(this->id > f.id);
    }

    friend ostream& operator << (ostream& output, const Faculty &f){
      output << "Faculty Name: " << f.name << endl;
      output << "Faculty ID: " << f.id << endl;
      output << "Level: " << f.level << endl;
      output << "Department : " << f.department << endl;
      output << "Advisee ID: " << f.numAdvisee << endl;
      return output;
  }
};
