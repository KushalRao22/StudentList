#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct Student{
  char firstName[10];
  char lastName[10];
  int num;
  float gpa;
};

void addStudent(char name[10]);

int main(){
  bool quit = false;
  char input[7];
  while(!quit){
    cout << "Type a valid command(ADD, PRINT, DELETE, QUIT)" << endl;
    cin >> input;
    if(strcmp(input,"ADD") == 0){
      cout << "First Name?" << endl;
      cin >> name;
      addStudent(name);
    }
    else if(strcmp(input,"PRINT") == 0){
      cout << "Print" << endl;
    }
    else if(strcmp(input,"DELETE") == 0){
      cout << "DELETE" << endl;
    }
    else if(strcmp(input,"QUIT") == 0){
      cout << "QUIT" << endl;
      quit = true;
    }
    else{
      cout << "Type a valid command(ADD, PRINT, DELETE, QUIT)" << endl;
    }

  }
  return 0;
}

void addStudent(char name[10]){
  
}
