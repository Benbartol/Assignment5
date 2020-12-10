//Ben Bartol
//ID: 2315721
//bartol@chapman.edu
//CPSC 350 - Rene German
#include "Member.h"
using namespace std;

Member::Member(){

}

Member::~Member(){

}

void Member::setID(int idnum){
  id = idnum;
}

int Member::getID(){
  return id;
}

string Member::getName(){
  return name;
}

string Member::getLevel(){
  return level;
}
