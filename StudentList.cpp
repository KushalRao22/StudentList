#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip> 
using namespace std;

typedef struct{
  char firstName[100];
  char lastName[100];
  float gpa;
  int id;
} Student;

void addStudent(vector<Student>* input);

void print(vector<Student> input);

void Remove(vector<Student>& input);

int main(){
  bool quit = false;
  vector<Student> students;
  char input[7];
  while(!quit){
    cout << "Type a valid command(ADD, PRINT, DELETE, QUIT)" << endl;
    cin >> input;
    if(strcmp(input,"ADD") == 0){
      addStudent(&students);
    }
    else if(strcmp(input,"PRINT") == 0){
      cout << "Print" << endl;
      print(students);

    }
    else if(strcmp(input,"DELETE") == 0){
      cout << "DELETE" << endl;
      Remove(students);
    }
    else if(strcmp(input,"QUIT") == 0){
      cout << "QUIT" << endl;
      quit = true;
    }
  }
  return 0;
}

void addStudent(vector<Student>* input){
  Student new_student;
  int id = -1;
  float gpa= -1;
  char firstName[100];
  char lastName[100];
  cout << "Input First Name" << endl;
  cin >> firstName;
  cout << "Input Last Name" << endl;
  cin >> lastName;
  cout << "Input Student ID" << endl;
  cin >> id;
  cout << "Input Student GPA" << endl;
  cin >> gpa;
  new_student.gpa = gpa;
  new_student.id = id;
  memcpy(new_student.firstName, firstName, 100);
  memcpy(new_student.lastName, lastName, 100);

  input->push_back(new_student);
}

void print(vector<Student> input){
  for(int i = 0; i < input.size(); i++){
    float gpa = input[i].gpa;
    cout << input[i].firstName << " " << input[i].lastName << " ID: " << 
    input[i].id << " GPA: " << setprecision(3) << gpa << endl;
  }
}

void Remove(vector<Student>& input){
  int removeID= -1;
  cout << "What is the ID number of the student you wish to remove?" << endl;
  cin >> removeID;
  for(int i = 0; i < input.size(); i++){
    if(input[i].id == removeID){
      input.erase(input.begin() + i);
      return;
    }
  }
}
