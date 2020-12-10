//Ben Bartol
//ID: 2315721
//bartol@chapman.edu
//CPSC 350 - Rene German

#include "Menu.h"

Menu::Menu(){

}

Menu::~Menu(){

}

void Menu::readFile(){
  ifstream fileMS;
  ifstream fileMF;

  string input;
  int numStudent = 0;
  int numFaculty = 0;
  int totalFaculty = 0;
  int totalAdvisee = 0;
  int numLine = 1;

  //Student info
  int stuID = 0;
  string stuName = "";
  string stuLevel = "";
  string stuMajor = "";
  double gpa = 0;
  int advisorID = 0;

  //Faculty info
  int facID = 0;
  string facName = "";
  string facLevel = "";
  string department = "";
  int adviseeID = 0;


  //importing the student
  fileMS.open("studentTable.txt");

  if(fileMS.is_open()){
    try{
      getline(fileMS, input);

      if(input != ""){
        numStudent = atoi(input.c_str());
      }
    }catch(exception e){
      cout << "Incorrect File Format... try again" << endl;
    }

    while(getline(fileMS, input)){
      switch(numLine){
        case 1: {
          if(input != "--"){
            cout << "Incorrect File Format... try again" << endl;
          }
          break;
        }
        case 2: {
          try{
            stuID = atoi(input.c_str());
          }catch(exception e){
            cout << "Incorrect File Format... try again" << endl;
          }
          break;
        }
        case 3: {
          stuName = input;
          break;
        }
        case 4: {
          stuLevel = input;
          break;
        }
        case 5: {
          stuMajor = input;
        }
        case 6: {
          try{
            gpa = atoi(input.c_str());
          }catch(exception e){
            cout << "Incorrect File Format... try again" << endl;
          }
          break;
        }
        case 7: {
          try{
            advisorID = atoi(input.c_str());

            Student *student = new Student(stuID, stuName, stuLevel, stuMajor, gpa, advisorID);

            TreeNode<Student> *studentNode = new TreeNode<Student>(student, stuID);
            masterStudent.insert(studentNode);

          }catch(exception e){
            cout << "Incorrect File Format... try again" << endl;
          }
          break;
        }
        defaut:
        break;
      }
      ++numLine;
      if(numLine > 7){
        numLine = 1;
      }
    }
  }else{
    cout << "No File Found for Student Table - Starting with blank file" << endl;
  }
  fileMS.close();

  //importing the faculty
  fileMF.open("facultyTable.txt");

  if(fileMF.is_open()){
    try{
      getline(fileMF, input);

      if(input != ""){
        numFaculty = atoi(input.c_str());
      }
    }catch(exception e){
      cout << "Incorrect File Format... Try Again" << endl;
    }

    while(getline(fileMF, input)){
      switch(numLine){
        case 1:{
          if(input != ""){
            cout << "Incorrect File Format... Try Again" << endl;
          }
          break;
        }
        case 2: {
          try{
            facID = atoi(input.c_str());
          }catch(exception e){
            cout << "Incorrect File Format... Try Again" << endl;
          }
          break;
        }
        case 3: {
          facName = input;
          break;
        }
        case 4: {
          facLevel = input;
          break;
        }
        case 5: {
          department = input;
          break;
        }
        case 6: {
          try{
            totalAdvisee = atoi(input.c_str());
          }catch(exception e){
            cout << "Incorrect File Format... Try Again" << endl;
          }

          Faculty *faculty = new Faculty(facID, facName, facLevel, department);
          totalFaculty++;

          for(int j = 0; j < totalAdvisee; ++j){
            getline(fileMF, input);
            try{
              adviseeID = atoi(input.c_str());
            }catch(exception e){
              cout << "Incorrect File Format... Try Again" << endl;
            }
            faculty->addAdvisee(adviseeID);
          }

          TreeNode<Faculty> *facultyNode = new TreeNode<Faculty>(faculty, facID);
          masterFaculty.insert(facultyNode);
          break;
        }
        default:
        break;
      }

      ++numLine;

      if(totalFaculty == numFaculty){
        break;
      }
      if(numLine > 6){
        numLine = 1;
      }
    }
  }else{
    cout << "No File Found For Faculty Table - Staring with blank file" << endl;
  }

  fileMF.close();
}



void Menu::writeFile(){
  ofstream fileMS;
  ofstream fileMF;

  //Student
  fileMS.open("studentTable.txt");
  if(fileMS.is_open()){
    fileMS << masterStudent.getSize() << endl;
    TreeNode<Student> *s = masterStudent.getRoot();
    outputMS(s, "studentTable.txt");
  }
  fileMS.close();

  //Faculty
  fileMF.open("facultyTable.txt");
  if(fileMF.is_open()){
    fileMF << masterFaculty.getSize() << endl;
    TreeNode<Faculty> *f = masterFaculty.getRoot();
    outputMF(f, "facultyTable.txt");
  }
  fileMF.close();
}

//traversing and printing the Student tree
void Menu::printMS(TreeNode<Student> *s){
  if(s != NULL){
    if(s->left != NULL){
      printMS(s->left);
    }
    s->data->printStudent();

    if(s->right != NULL){
      printMS(s->right);
    }
  }else{
    cout << "Student Database is Empty" << endl;
  }
}

//traversing and printing the Faculty tree
void Menu::printMF(TreeNode<Faculty> *f){
  if(f != NULL){
    if(f->left != NULL){
      printMF(f->left);
    }
    f->data->printFaculty();

    if(f->right != NULL){
      printMF(f->right);
    }
  }else{
    cout << "Faculty Database is Empty" << endl;
  }
}


void Menu::outputMS(TreeNode<Student> *s, string student){
  ofstream outFS;
  outFS.open(student.c_str());

  if(s != NULL){
    outFS << "__" << endl;
    outFS << s->data->getID() << endl;
    outFS << s->data->getName() << endl;
    outFS << s->data->getLevel() << endl;
    outFS << s->data->getMajor() << endl;
    outFS << s->data->getGPA() << endl;
    outFS << s->data->getAdvisor() << endl;

    if(s->left != NULL){
      outputMS(s->left, student);
    }

    if(s->right != NULL){
      outputMS(s->right, student);
    }
  }else{
    cout << "Student Database is Empty" << endl;
  }

  outFS.close();
}


void Menu::outputMF(TreeNode<Faculty> *f, string faculty){
  ofstream outFS;
  outFS.open(faculty.c_str());

  if(f != NULL){
    outFS << "__" << endl;
    outFS << f->data->getID() << endl;
    outFS << f->data->getName() << endl;
    outFS << f->data->getLevel() << endl;
    outFS << f->data->getDepartment() << endl;
    outFS << f->data->getID() << endl;

    if(f->data->getAdviseeID() > 0){
      for(int i = 0; i < f->data->maxSize; ++i){
        if(f->data->adviseeArray[i] != -1){
          outFS << f->data->adviseeArray[i] << endl;
        }
      }
    }

    if(f->left != NULL){
      outputMF(f->left, faculty);
    }
    if(f->right != NULL){
      outputMF(f->right, faculty);
    }
  }else{
    cout << "Faculty Database is Empty" << endl;
  }

  outFS.close();
}


TreeNode<Student>* Menu::getMSroot(){
  return masterStudent.getRoot();
}

TreeNode<Faculty>* Menu:: getMFroot(){
  return masterFaculty.getRoot();
}

void Menu::printMenu(){
  string input;
  int numInput;
  bool error;
  bool running = true;

  while(running){
    cout << "~MENU~" << endl;
    cout << 1 << "Print ALL Student Info (by ascending ID)" << endl;
    cout << 2 << "Print ALL Faculty Info (by ascending ID)" << endl;
    cout << 3 << "Print Indiv. Student Info (by ID)" << endl;
    cout << 4 << "Print Indiv. Faculty Info (by ID)" << endl;
    cout << 5 << "Print Advisor Info (by Student ID)" << endl;
    cout << 6 << "Print Advisee Info (by Faculty ID)" << endl;
    cout << 7 << "Add New Student" << endl;
    cout << 8 << "Remove Student (by ID)" << endl;
    cout << 9 << "Add New Faculty (by ID)" << endl;
    cout << 10 << "Remove Faculty (by ID)" << endl;
    cout << 11 << "Change Advisor (by Student ID and Faculty ID)" << endl;
    cout << 12 << "Remove Advisee (by Student ID and Faculty ID)" << endl;
    cout << 13 << "Rollback" << endl;
    cout << 14 << "Exit" << endl;
    cout << "Please select an option...";
    cin >> input;

    try{
      numInput = atoi(input.c_str());

      if(numInput < 0 || numInput > 14){
        cout << "Enter Valid Option" << endl;
        error = true;
        numInput = 15;
      }
    }catch(exception e){
      error = false;
      numInput = 15;
    }

    switch(numInput){
      case 1:
        printAllStudents();
        break;
      case 2:
        printAllFaculty();
        break;
      case 3:
        printStudent();
        break;
      case 4:
        printFaculty();
        break;
      case 5:
        printAdvisor();
        break;
      case 6:
        printAdvisee();
        break;
      case 7:
        addStudent();
        break;
      case 8:
        removeStudent();
        break;
      case 9:
        addFaculty();
        break;
      case 10:
        removeFaculty();
        break;
      case 11:
        changeAdvisor();
        break;
      case 12:
        removeAdvisee();
        break;
      case 13:
        rollback();
        break;
      case 14:
        exit();
        return;
      default:
        if(error == true){
          continue;
        }else{
          cout << "Enter Valid Input" << endl;
          continue;
        }
    }
  }
}

void Menu::printAllStudents(){
  if(masterStudent.isEmpty()){
    cout << "Student Database is Empty" << endl;
  }else{
    printMS(masterStudent.getRoot());
  }
}

void Menu::printAllFaculty(){
  if(masterFaculty.isEmpty()){
    cout << "Faculty Database is Empty" << endl;
  }else{
    printMF(masterFaculty.getRoot());
  }
}

void Menu::printStudent(){
  string input;
  int stuID;

  if(masterStudent.isEmpty()){
    cout << "Student Database is Empty" << endl;
  }else{
    while(true){
      cout << "Provide a Student ID";
      cin >> input;

      try{
        stuID = atoi(input.c_str());

        if(masterStudent.contains(stuID)){
          masterStudent.find(stuID)->printStudent();
          break;
        }else{
          cout << "Student ID: " << stuID << "isn't in database" << endl;
        }
      }catch(exception e){
        cout << "Enter Valid Input" << endl;
      }
    }
  }
}



void Menu::printFaculty(){
  string input;
  int facID;

  if(masterFaculty.isEmpty()){
    cout << "Faculty Database is Empty" << endl;
  }else{
    while(true){
      cout << "Provide a Faculty ID";
      cin >> input;

      try{
        facID = atoi(input.c_str());

        if(masterFaculty.contains(facID)){
          masterFaculty.find(facID)->printFaculty();
          break;
        }else{
          cout << "Facilty ID: " << facID << "isn't in the database" << endl;
         }
      }catch(exception e){
        cout << "Enter Valid Input" << endl;
      }
    }
  }
}


void Menu::printAdvisor(){
  string input;
  int stuID;

  if(masterStudent.isEmpty()){
    cout << "Student Database is Empty" << endl;
  }else{
    cout << "List of Students in Database:" << endl;
    printMS(masterStudent.getRoot());

    while(true){
      cout << "Provide a Student ID: ";
      cin >> input;

      try{
        stuID = atoi(input.c_str());

        if(masterStudent.contains(stuID)){
          Student *student = masterStudent.find(stuID);

          masterFaculty.find(student->getAdvisor())->printFaculty();
          break;
        }else{
          cout << "Student ID: " << stuID << "isn't in the database" << endl;
         }
      }catch(exception e){
        cout << "Enter Valid Input" << endl;
      }
    }
  }
}

void Menu::addStudent(){
  string input;


  bool validID = false;
  srand(time(NULL));
  int stuID = rand() % 4000 + 1000;

  while(validID == false){
    if(masterStudent.contains(stuID) == false){
      validID = true;
    }else{
      int stuID = rand() % 4000 + 1000;
      validID = false;
    }
  }
  cout << "New Student ID: " << stuID << endl;
  cin.fail();

  string name;
  cout << "New Student Name: ";
  cin.ignore();
  getline(cin, name);

  string level;
  cout << "New Student Grade: ";
  cin >> level;

  string major;
  cout << "New Student Major: ";
  cin >> major;

  double gpa;
  while(true){
    input = "";
    cout << "New Student GPA: " ;
    cin >> input;

    try{
      gpa = atof(input.c_str());

      if(gpa > 5 || gpa < 0){
        cout << "Enter GPA on 5 Point Scale" << endl;
      }else{
        break;
      }
    }catch(exception e){
      cout << "Enter Valid Input" << endl;
    }
  }
  int advisorID;

  if(!masterFaculty.isEmpty()){
    while(true){
      input = "";
      cout << "New Student Advisor ID: ";
      cin >> input;

      try{
        advisorID = atoi(input.c_str());

        if(masterFaculty.contains(advisorID) || advisorID == -1){
          Faculty *faculty = masterFaculty.find(advisorID);
          faculty->addAdvisee(stuID);
          break;
        }else{
          input = "";
          cout << "Faculty ID: " << advisorID << "isn't in the database" << endl;
          cout << "Do you want a list of all Faculty? (y/n)";
          cin >> input;

          if(input == "Y" || input == "y"){
            printAllFaculty();
          }else{
            break;
          }
        }
      }catch(exception e){
        cout << "Enter Valid Input" << endl;
      }
    }
  }else{
    advisorID = -1;
  }

  Student *student = new Student(stuID, name, level, major, gpa, advisorID);
  TreeNode<Student> *studentNode = new TreeNode<Student>(student, stuID);
  masterStudent.insert(studentNode);
}

void Menu::removeStudent(){
  string input;
  int stuID = 0;

  if(masterStudent.isEmpty()){
    cout << "Student Database is Empty" << endl;
  }else{
    cout << "List of Students in Database: " << endl;
    printMS(masterStudent.getRoot());

    while(true){
      input = "";
      cout << "Provide a Student ID: ";
      cin >> input;

      try{
        stuID = atoi(input.c_str());

        if(masterStudent.contains(stuID)){
          if(masterStudent.find(stuID)->getAdvisor() != -1){
            masterFaculty.find(masterStudent.find(stuID)->getAdvisor())->removeAdvisee(stuID);
          }
          masterStudent.erase(stuID);
          break;
        }else{
          cout << "Student ID: " << stuID << "isn't in Database" << endl;
        }
      }catch(exception e){
        cout << "Provide Valid Input" << endl;
      }
    }
  }
}

void Menu::addFaculty(){
  string input;
  int newAdviseeTotal = 0;
  int stuID = 0;


  bool validID = false;
  srand(time(NULL));
  int facID = rand() % 5000 + 5000;

  while(validID == false){
    if(masterFaculty.contains(facID) == false){
      validID = true;
    }else{
      int facID = rand() % 5000 + 5000;
      validID = false;
    }
  }

  cout << "New Faculty ID: " << facID << endl;
  cin.clear();

  string name;
  cout << "New Faculty Name: ";
  cin.ignore();
  getline(cin, name);

  string level;
  cout << "New Faculty Level: ";
  cin >> level;

  string department;
  cout << "New Faculty Department: ";
  cin >> department;

  Faculty *faculty = new Faculty(facID, name, level, department);

  if(!masterStudent.isEmpty()){
    while(true){
      cout << "How many advisees does the new faculty have?";
      cin >> input;

      try{
        newAdviseeTotal = atoi(input.c_str());
        break;
      }catch(exception e){
        cout << "Provide Valid Input" << endl;
      }
    }

    if(newAdviseeTotal != 0){
      cout << "List of Students in Database: " << endl;
      printAllStudents();
    }

    for(int i = 0; i < newAdviseeTotal; ++i){
      while(true){
        input = "";
        cout << "(" << newAdviseeTotal << " Left) Provide a Student ID: ";
        cin >> input;

        try{
          stuID = atoi(input.c_str());

          if(masterStudent.contains(stuID)){
            faculty->addAdvisee(stuID);
            masterStudent.find(stuID)->setAdvisor(facID);
            --newAdviseeTotal;
            break;
          }else{
            cout << "Student ID: " << stuID << "isn't in Database" << endl;
          }
        }catch(exception e){
          cout << "Provide Valid Input" << endl;
        }
      }
    }
  }
}

void Menu::removeFaculty(){
  string input;
  int facID = 0;
  int transferID = 0;

  if(masterFaculty.isEmpty()){
    cout << "Faculty Database is Empty" << endl;
  }else{
    cout << "Faculty ID: in Database: " << endl;
    printMF(masterFaculty.getRoot());

    while(true){

      input = "";
      cout << "Provide a Faculty ID: ";
      cin >> input;

      try{
        facID = atoi(input.c_str());
        if(masterFaculty.contains(facID)){
          if(masterFaculty.find(facID)->numAdvisee > 0){
            while(true){
              input = "";
              cout << "Provide a Faculty ID to tansfer to: ";
              cin >> input;

              try{
                transferID = atoi(input.c_str());

                if(masterFaculty.contains(transferID)){
                  for(int i = 0; i < masterFaculty.find(facID)->maxSize; ++i){
                    if(masterFaculty.find(facID)->adviseeArray[i] != 1){
                      masterStudent.find(masterFaculty.find(facID)->adviseeArray[i])->setAdvisor(transferID);
                    }
                  }
                }else{
                  cout << "Faculty Transfer ID: " << transferID << "is't in the Database" << endl;
                }
                break;
              }catch(exception e){
                cout << "Provide Valid Input" << endl;
              }
            }
          }else{
            masterFaculty.erase(facID);
            break;
          }
        }else{
          cout << "Facilty ID: " << facID << " isn't in the Database" << endl;
        }
        break;
      }catch(exception e){
        cout << "Provide Valid Input" << endl;
      }
    }
  }
}


void Menu::changeAdvisor(){
  string input;
  int stuID = 0;
  int facID = 0;

  if(masterFaculty.isEmpty() || masterStudent.isEmpty()){
    cout << "Student and/or Faculty Database is Empty" << endl;
  }else{
    cout << "Students in Database: " << endl;
    printMS(masterStudent.getRoot());

    while(true){
      input = "";
      cout << "Provide a Faculty ID: ";
      cin >> input;

      try{
        stuID = atoi(input.c_str());

        if(masterStudent.contains(facID)){
          while(true){
            input = "";
            cout << "Provide a Faculty ID: ";
            cin >> input;

            try{
              facID = atoi(input.c_str());

              if(masterFaculty.contains(stuID)){
                break;
              }else{
                cout << "Facult ID: " << facID << "isn't in the Database" << endl;
              }
            }catch(exception e){
              cout << "Provide Valid Input" << endl;
            }
          }
          break;
        }else{
          cout << "Student ID: " << stuID << "isn't in the Database" << endl;
        }
      }catch(exception e){
          cout << "Provide Valid Input" << endl;
        }
      }

      masterStudent.find(stuID)->setAdvisor(facID);
      masterFaculty.find(facID)->addAdvisee(stuID);
    }
  }

void Menu::removeAdvisee(){
  string input;
  int stuID = 0;
  int facID = 0;

  if(masterFaculty.isEmpty() || masterStudent.isEmpty()){
    cout << "Student and/or Faculty Databse is Empty" << endl;
  }else{
    cout << "Faculty in Database: ";
    printMF(masterFaculty.getRoot());

    while(true){
      input = "";
      cout << "Provide a Faculty ID: ";
      cin >> input;

      try{
        stuID = atoi(input.c_str());

        if(masterStudent.contains(stuID)){
          break;
        }else{
          cout << "Student ID: " << stuID << "isn't in the Database" << endl;
        }
      }catch(exception e){
        cout << "Enter Valid Input" << endl;
      }
    }

    if(masterFaculty.find(facID)->removeAdvisee(stuID)){
      masterStudent.find(stuID)->setAdvisor(-1);
    }

    input = "";
    cout << "Would you like to set a new Advisor? (y/n)";
    cin >> input;

    if(input == "Y" || (input == "y")){
      cout << "Printing All Faculty...";
      printAllFaculty();

      while(true){
        input = "";
        cout << "Provide Faculty ID: ";
        cin >> input;

        try{
          facID = atoi(input.c_str());

          if(masterFaculty.contains(facID)){
            break;
          }else{
            cout << "Faculty ID: " << facID << "isn't in the Database" << endl;
          }
        }catch(exception e){
          cout << "Provide Valid Input" << endl;
        }
      }

      masterStudent.find(stuID)->setAdvisor(facID);
    }
  }
}

void Menu::rollback(){
  //unable to complete this function
}

void Menu::exit(){
  cout << "Exiting Database..." << endl;
}
