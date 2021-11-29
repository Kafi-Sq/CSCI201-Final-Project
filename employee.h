#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee{
  private:
    int employeeID;
    string firstName;
    string lastName;
    float workingHours;
    float costPerHour;
    float deduction;
    double annualSalary;
  public:
    void set_employeeID(int);
    int get_employeeID();
    void set_firstName(string);
    string get_firstName();
    void set_lastName(string);
    string get_lastName();
    void set_workingHours(float);
    float get_workingHours();
    void set_costPerHour(float);
    float get_costPerHour();
    void set_deduction(float);
    double get_deduction();
    void set_annualSalary(double);
    double get_annualSalary();
};

#endif