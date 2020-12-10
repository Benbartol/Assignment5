//Ben Bartol
//ID: 2315721
//bartol@chapman.edu
//CPSC 350 - Rene German
#include "Student.h"
using namespace std;

Student::Student(){

}

Student::~Student(){

}

Student::Student(int xID, string xName, string xLevel, string xMajor, double xGPA, int xAdvisorID){
  id = xID;
  name = xName;
  level = xLevel;
  major = xMajor;
  gpa = xGPA;
  advisorID = xAdvisorID;
}

string Student::getMajor(){
  return major;
}

double Student::getGPA(){
  return gpa;
}

int Student::getAdvisor(){
  return advisorID;
}

void Student::setAdvisor(int xAdvisorID){
  advisorID = xAdvisorID;
}

void Student::printStudent(){
  cout << "Student name: " << name << endl;
  cout << "Student ID: " << id << endl;
  cout << "Grade: " << level << endl;
  cout << "Major: " << major << endl;
  cout << "GPA: " << gpa << endl;
  cout << "Advisor: " << advisorID << endl;
}
