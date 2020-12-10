//Ben Bartol
//ID: 2315721
//bartol@chapman.edu
//CPSC 350 - Rene German
#include <iostream>
#include "Menu.h"
using namespace std;

int main(int argc, char** argv){
  Menu m;

  m.readFile();
  m.printMenu();
  m.writeFile();

  return 0;
}
