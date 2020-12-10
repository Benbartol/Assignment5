//Ben Bartol
//ID: 2315721
//bartol@chapman.edu
//CPSC 350 - Rene German
#include <iostream>
#include "Member.h"
using namespace std;

class Student : public Member{
  private:

  public:
    string major;
    double gpa;
    int advisorID;

    Student();
    ~Student();
    Student(int xID, string xName, string xLevel, string xMajor, double xGPA, int xAdvisorID);

    string getMajor();
    double getGPA();

    void setAdvisor(int xAdvisorID);
    int getAdvisor();
    void printStudent();

    //setting operators
    bool operator == (const Student &s){
      return(this->id == s.id);
    }
    bool operator != (const Student &s){
      return(this->id != s.id);
    }
    bool operator <= (const Student &s){
      return(this->id <= s.id);
    }
    bool operator >= (const Student &s){
      return(this->id >= s.id);
    }
    bool operator < (const Student &s){
      return(this->id < s.id);
    }
    bool operator > (const Student &s){
      return(this->id > s.id);
    }

    friend ostream& operator << (ostream& output, const Student &s){
      output << "Student Name: " << s.name << endl;
      output << "Student ID: " << s.id << endl;
      output << "Level: " << s.level << endl;
      output << "Major : " << s.major << endl;
      output << "GPA: " << s.gpa << endl;
      output << "Advisor ID: " << s.advisorID << endl;
      return output;
    }

};
