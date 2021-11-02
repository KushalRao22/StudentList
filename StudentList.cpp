/*
This program adds removes and prints students from a list
Last modified: 11/2/21
By: Kushal Rao
*/

//imports
#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip> 

using namespace std;

typedef struct{//Create a student struct
  char firstName[100];
  char lastName[100];
  float gpa;
  int id;
} Student;

void addStudent(vector<Student>* input);//Method for adding students to vector

void print(vector<Student> input);//Method to print all students in vector

void Remove(vector<Student>& input);//Method for removing students from vector

int main(){
  bool quit = false;//bool to check when user wants to quit
  vector<Student> students;//Vector of students
  char input[7];
  while(!quit){
    cout << "Type a valid command(ADD, PRINT, DELETE, QUIT)" << endl;//Prompt user for input
    cin >> input;
    if(strcmp(input,"ADD") == 0){//If user wants to add
      addStudent(&students);
    }
    else if(strcmp(input,"PRINT") == 0){//If user wants to print
      cout << "Print" << endl;
      print(students);

    }
    else if(strcmp(input,"DELETE") == 0){//If user wants to delete
      cout << "DELETE" << endl;
      Remove(students);
    }
    else if(strcmp(input,"QUIT") == 0){//If user wants to quit
      cout << "QUIT" << endl;
      quit = true;
    }
  }
  return 0;
}

void addStudent(vector<Student>* input){//Add student method
  Student new_student;//Create new student
  int id = -1;
  float gpa= -1;
  char firstName[100];
  char lastName[100];
  cout << "Input First Name" << endl;//Prompt user for first name
  cin >> firstName;
  cout << "Input Last Name" << endl;//Prompt user for last name
  cin >> lastName;
  cout << "Input Student ID" << endl;//Prompt user for student id
  cin >> id;
  cout << "Input Student GPA" << endl;//Prompt user for GPA
  cin >> gpa;
  new_student.gpa = gpa;//set the new students GPA to the GPA float.
  new_student.id = id;//set the new students id to the id int.
  memcpy(new_student.firstName, firstName, 100);//set the new students first name to the first name char array.
  memcpy(new_student.lastName, lastName, 100);//set the new students last name to the last name char array.

  input->push_back(new_student);//Push new student into vector
}

void print(vector<Student> input){//Method to print out all the students
  for(int i = 0; i < input.size(); i++){//For each student
    float gpa = input[i].gpa;//format gpa to have to decimals 
    cout << input[i].firstName << " " << input[i].lastName << " ID: " << 
    input[i].id << " GPA: " << setprecision(3) << gpa << endl;//Format and print
  }
}

void Remove(vector<Student>& input){//Method to remove students
  int removeID= -1;//ID for removal
  cout << "What is the ID number of the student you wish to remove?" << endl;
  cin >> removeID;//Find the idea to remove scince all ids are differrent
  for(int i = 0; i < input.size(); i++){//for all the vectors
    if(input[i].id == removeID){//If the id matches the student's id
      input.erase(input.begin() + i);//remove the student frome the vector
      return;//Return
    }
  }
}
