// Hassen Hassen
// Final Project
// CSCI201

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Employee Class
class Employee {
  private:
  // Private Attributes
    int employeeID;
    string firstName;
    string lastName;
    float workingHours;
    float costPerHour;
    float deduction;
    double annualSalary;
  public:
  // Setters
    void set_employeeID(int e){
      employeeID = e;
    }
    void set_firstName(string f){
      firstName = f;
    }
    void set_lastName(string l){
      lastName = l;
    }
    void set_workingHours(float wh){
      workingHours = wh;
    }
    void set_costPerHour(float cph){
      costPerHour = cph;
    }
    void set_deduction(float d){
      deduction = d;
    }
    void set_annualSalary(double as){
      annualSalary = as;
    }
  // Getters
    int get_employeeID(){ return employeeID; }
    string get_firstName(){ return firstName; }
    string get_lastName(){ return lastName; }
    float get_workingHours(){ return workingHours; }
    float get_costPerHour(){ return costPerHour; }
    float get_deduction() {return deduction; }
    double get_annualSalary(){ return annualSalary; }
};

// HRM Class
class HRM{
  public:
    Employee E[100];
    int numOfEmp;
    void addEmployee();
    void deleteEmployee(){cout <<"df";};
    void updateEmployee(){cout <<"df";};
    void searchEmployee();
};

int empID, count = 0;

void HRM::addEmployee(){
  char answer;
  do{
    int eid;
    string firstName, lastName;
    float workingHours, costPerHour, deduction;
    double annualSalary;
    E[count].set_employeeID(empID);
    cout << "Please enter the first name of an Employee? ";
    cin >> firstName;
    E[count].set_firstName(firstName);
    cout << "Please enter the last name of an Employee? ";
    cin >> lastName;
    E[count].set_lastName(lastName);
    cout << "How many hours a week is his/her work? ";
    cin >> workingHours;
    if(workingHours < 1 || workingHours > 60){
      cout << "Invalid Entry!" << endl;
      break;
    }
    E[count].set_workingHours(workingHours);
    cout << "How much per hour is his/her wage? ";
    cin >> costPerHour;
    if(costPerHour < 0){
      cout << "Invalid Entry!" << endl;
      break;
    }
    E[count].set_costPerHour(costPerHour);
    cout << "How much total deduction? ";
    cin >> deduction;
    if(deduction < 0){
      cout << "Invalid Entry!" << endl;
      break;
    }
    annualSalary = (workingHours * costPerHour - deduction) * 52;
    E[count].set_annualSalary(annualSalary);
    E[count].set_deduction(deduction);
    cout << "The Employee with the following information has been added to the system: " << endl;
    cout << "Employee ID\tFirst Name\tLast Name\tSalary per year($)" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << E[count].get_employeeID() << "\t" << E[count].get_firstName() << "\t" << E[count].get_lastName() << "\t" << E[count].get_annualSalary() << endl;
    empID++;
    count++;
    cout << "Do you want to add another employee(y/n)? ";
    cin >> answer;
  }while(answer != 'n');
}

void HRM::searchEmployee(){
  char answer;
  do{
    int x;
    int index;
    double annualSalary;
    cout << "Please enter the employee ID? ";
    cin >> x;

    for (int i = 0; i < count; i++){
      if(E[i].get_employeeID() == x){
        index = i;
        annualSalary = (E[i].get_workingHours() * E[i].get_costPerHour() - E[i].get_deduction()) * 52;
      }
    }
    E[index].set_annualSalary(annualSalary);
    cout << "Employee ID\tFirst Name\tLast Name\tSalary per year($)" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << E[index].get_employeeID() << "\t" << E[index].get_firstName() << "\t" << E[index].get_lastName() << "\t" << E[index].get_annualSalary() << endl;
    cout << "Do you want to do a new search(y/n)? ";
    cin >> answer;
  }while(answer != 'n');
  
}

int main(){
  
  HRM HR;
  
  ifstream inf;
  inf.open("employee.txt");
  if(!inf){
    cout << "File doesn't Exist!" << endl;
    return 0;
  }
  int i = 0;
  int eid;
  string firstName, lastName;
  float workingHours, costPerHour, deduction;
  while(!inf.eof()){
    inf >> eid; 
    HR.E[i].set_employeeID(eid);
    inf >> firstName; 
    HR.E[i].set_firstName(firstName);
    inf >> lastName; 
    HR.E[i].set_lastName(lastName);
    inf >> workingHours; 
    HR.E[i].set_workingHours(workingHours);
    inf >> costPerHour; 
    HR.E[i].set_costPerHour(costPerHour);
    inf >> deduction; 
    HR.E[i].set_deduction(deduction);
    i++;
    count++;
    empID = eid + 1;
  }
  inf.close();
  

  // Main Menu
  int choice;
  do{
    cout << "\tMain Menu" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. Delete an Employee" << endl;
    cout << "3. Update Employee Information" << endl;
    cout << "4. Search an Employee" << endl;
    cout << "5. Quit" << endl;
    cin >> choice;

    switch (choice){
    case 1:
      HR.addEmployee();
      break;
    case 2:
      HR.deleteEmployee();
      break;
    case 3:
      HR.updateEmployee();
      break;
    case 4:
      HR.searchEmployee();
      break;
  }
  }while (choice != 5);

  return 0;
}