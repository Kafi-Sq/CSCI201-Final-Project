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
  // Public attributes
  public:
    Employee E[100];
    int numOfEmp;
    void addEmployee();
    void deleteEmployee();
    void updateEmployee();
    void searchEmployee();
};

// Global variables for ID and the employee count
int empID, count = 0;

// Function to add Employees
void HRM::addEmployee(){
  // Do while parameter
  char answer;
  do{
    // Declarations for inputs
    int eid;
    string firstName, lastName;
    float workingHours, costPerHour, deduction;
    double annualSalary;
    // Setting the inputs from the user in the employee array
    E[count].set_employeeID(empID);
    cout << "Please enter the first name of an Employee? ";
    cin >> firstName;
    E[count].set_firstName(firstName);
    cout << "Please enter the last name of an Employee? ";
    cin >> lastName;
    E[count].set_lastName(lastName);
    cout << "How many hours a week is his/her work? ";
    cin >> workingHours;
    // Check for inputted value
    if(workingHours < 1 || workingHours > 60){
      cout << "Invalid Entry!" << endl;
      break;
    }
    E[count].set_workingHours(workingHours);
    cout << "How much per hour is his/her wage? ";
    cin >> costPerHour;
    // Check for inputted value
    if(costPerHour < 0){
      cout << "Invalid Entry!" << endl;
      break;
    }
    E[count].set_costPerHour(costPerHour);
    cout << "How much total deduction? ";
    cin >> deduction;
    // Check for inputted value
    if(deduction < 0){
      cout << "Invalid Entry!" << endl;
      break;
    }
    // Calculating and setting the annual salary
    annualSalary = (workingHours * costPerHour - deduction) * 52;
    E[count].set_annualSalary(annualSalary);
    E[count].set_deduction(deduction);
    // Displaying the information that was entered by the user
    cout << "The Employee with the following information has been added to the system: " << endl;
    cout << "Employee ID\tFirst Name\tLast Name\tSalary per year($)" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << E[count].get_employeeID() << "\t" << E[count].get_firstName() << "\t" << E[count].get_lastName() << "\t" << E[count].get_annualSalary() << endl;
    empID++;
    count++;
    cout << "Do you want to add another employee(y/n)? ";
    // Taking in input for the do while loop
    cin >> answer;
  }while(answer != 'n');
}

// Function to delete employee
void HRM::deleteEmployee(){
  // Do while parameter
  char answer;
  do {
    // Declarations for inputs from user
    int index, ID;
    double annualSalary;
    char ans;
    // Getting the ID from the user
    cout << "Please enter the employee ID? ";
    cin >> ID;
    // Searching for the ID
    for (int i = 0; i < count; i++){
      if(E[i].get_employeeID() == ID){
        index = i;
        annualSalary = (E[i].get_workingHours() * E[i].get_costPerHour() - E[i].get_deduction()) * 52;
      }
    }
    // Found the ID and asking if user wants to delete
    cout << "Do you really want to delete " << E[index].get_firstName() << " " << E[index].get_lastName() << "? ";
    cin >> ans;
    // Deleting employee if answer is yes
    if(ans != 'n'){
      E[index].set_employeeID(-1);
      cout << "The employee " << E[index].get_firstName() << " " << E[index].get_lastName() << " has been deleted." << endl;
    }
    cout << "Do you want to repeat delete by entering new employee ID? ";
    // Input for the do while
    cin >> answer;
  }while(answer != 'n');
}

// Function to update
void HRM::updateEmployee(){
  char answer;
  do {
    // Decalarations for inputs from user
    int index, ID, choice;
    double annualSalary;
    string fName, lName;
    float workingHours, costPerHour, deduction;
    // Asking for ID
    cout << "Please enter the employee ID? ";
    cin >> ID;
    // Searching for employee
    for (int i = 0; i < count; i++){
      if(E[i].get_employeeID() == ID){
        index = i;
        annualSalary = (E[i].get_workingHours() * E[i].get_costPerHour() - E[i].get_deduction()) * 52;
      }
    }
    // Asking for which choice user wants to update 
    cout << "Please enter the related number of field which you would like to update? (1. First Name, 2. Family Name, 3. Working Hours per week, 4. Payment per one hour, 5. Deduction)? ";
    cin >> choice;
    // Check for invalid choice
    if (choice < 1 || choice > 5){
      cout << "Invalid Choice!";
    }else{
      // Swtich for what user wants to update
      switch(choice){
        // First name
        case 1:
          cout << "Please enter the new first name for " << E[index].get_firstName() << " " << E[index].get_lastName() << "? ";
          cin >> fName;
          E[index].set_firstName(fName);
          break;
        //Last name
        case 2:
          cout << "Please enter the new last name for " << E[index].get_firstName() << " " << E[index].get_lastName() << "? ";
          cin >> lName;
          E[index].set_firstName(lName);
          break;
        // Working hours
        case 3:
          cout << "Please enter the new working hours for " << E[index].get_firstName() << " " << E[index].get_lastName() << "? ";
          cin >> workingHours;
          E[index].set_workingHours(workingHours);
          break;
        // Cost per hour
        case 4:
          cout << "Please enter the new cost per hour for " << E[index].get_firstName() << " " << E[index].get_lastName() << "? ";
          cin >> costPerHour;
          E[index].set_costPerHour(costPerHour);
          break;
        // Deduction
        case 5:
          cout << "Please enter the new deduction for " << E[index].get_firstName() << " " << E[index].get_lastName() << "? ";
          cin >> deduction;
          E[index].set_deduction(deduction);
          break;
      }
    }
    // Displaying employee has been updated
    cout << "The information for " << E[index].get_firstName() << " " << E[index].get_lastName() << " has been updated." << endl;
    cout << "Do you want to repeat update by entering new employee ID? ";
    // Input for the do while
    cin >> answer;
  }while (answer != 'n');
}

// Function to search for an employee
void HRM::searchEmployee(){
  // Do while parameter
  char answer;
  do{
    // Declarations for inputs
    int x;
    int index;
    double annualSalary;
    // Asking user to enter employee ID
    cout << "Please enter the employee ID? ";
    cin >> x;
    // Searching for employee
    for (int i = 0; i < count; i++){
      if(E[i].get_employeeID() == x){
        index = i;
        annualSalary = (E[i].get_workingHours() * E[i].get_costPerHour() - E[i].get_deduction()) * 52;
      }
    }
    // Displaying information for employee found
    E[index].set_annualSalary(annualSalary);
    cout << "Employee ID\tFirst Name\tLast Name\tSalary per year($)" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << E[index].get_employeeID() << "\t" << E[index].get_firstName() << "\t" << E[index].get_lastName() << "\t" << E[index].get_annualSalary() << endl;
    cout << "Do you want to do a new search(y/n)? ";
    // Do while input
    cin >> answer;
  }while(answer != 'n');
  
}
// Main function
int main(){
  // Making the class
  HRM HR;
  // Opening file and reading the employees in the file
  ifstream inf;
  inf.open("employee.txt");
  if(!inf){
    cout << "File doesn't Exist!" << endl;
    return 0;
  }
  // Declarations for inputs
  int i = 0;
  int eid;
  string firstName, lastName;
  float workingHours, costPerHour, deduction;
  // Reading information from the file and setting them into the array.
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
  // Calling the function that corresponds with the choice from the user
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
  // Reading information back into file when user quits the program
  if(choice == 5){
      for (int i = 0; i < count; i++){
        if(HR.E[i].get_employeeID() != -1){
          // Opening file
          ofstream inf;
          inf.open("employee.txt");
          if(!inf){
            cout << "File doesn't exist\n";
            return 0;
          }
          // Reading information into file
          inf << HR.E[i].get_employeeID() << " " << HR.E[i].get_firstName() << " " << HR.E[i].get_lastName() << " " << HR.E[i].get_workingHours() << " " << HR.E[i].get_costPerHour() << " " << HR.E[i].get_deduction();
          inf.close();
        }
      }
    }

  return 0;
}