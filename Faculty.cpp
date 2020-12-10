//Ben Bartol
//ID: 2315721
//bartol@chapman.edu
//CPSC 350 - Rene German
#include "Faculty.h"
using namespace std;

Faculty::Faculty(){

}

Faculty::~Faculty(){
  delete []adviseeArray;
}

Faculty::Faculty(int xID, string xName, string xLevel, string xDepartment){
  id = xID;
  name = xName;
  level = xLevel;
  department = xDepartment;

  adviseeArray = new int[5];
  numAdvisee = 0;
  maxSize = 5;

  for(int i = 0; i < 5; ++i){
    adviseeArray[i] = -1;
  }
}

void Faculty::printFaculty(){
  cout << "Faculty Name: " << name << endl;
  cout << "Faculty ID: " << id << endl;
  cout << "Level: " << level << endl;
  cout << "Department: " << department << endl;
  cout << "Advisee ID: ";
  printAdvisee();
}

void Faculty::printAdvisee(){
  if(numAdvisee == 0){
    cout << "None";
  }else{
    for(int i = 0; i < maxSize; ++i){
      if(adviseeArray[i] != -1){
        cout << adviseeArray[i];
        if(i < numAdvisee - 1){
          cout << endl;
        }
      }
    }
  }
  cout << endl;
}

string Faculty::getDepartment(){
  return department;
}

int Faculty::getAdviseeID(){
  return numAdvisee;
}
