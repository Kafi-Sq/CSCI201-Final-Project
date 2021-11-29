#include <iostream>
#include <fstream>
#include <string>
#include "employee.h"
#include "HRM.h"
using namespace std;

int empID, count = 0;
int main(){
  int choice;
  
  ifstream inf;
  inf.open("employee.txt");
  

// Main Menu
  do {
    cout << "Main Menu" << endl;
    cout << "1. Add New Employee" << endl;
    cout << "2. Delete an Employee" << endl;
    cout << "3. Update Employee Information" << endl;
    cout << "4. Search for an Employee" << endl;
    cout << "5. Quit" << endl;
    cin >> choice;

    switch(choice){
    case 1:
      cout << "case 1" << endl;
      break;
    case 2:
      cout << "case 1" << endl;
      break;
    case 3:
      cout << "case 1" << endl;
      break;
    case 4:
      cout << "case 1" << endl;
      break;
  }
  }while(choice != 5);

}