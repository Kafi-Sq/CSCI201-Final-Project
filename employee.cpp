#include <iostream>
#include "employee.h"
using namespace std;

void Employee::set_employeeID(int e){
  employeeID = e;
}

int Employee::get_employeeID(){
  return employeeID;
}

void Employee::set_firstName(string f){
  firstName = f;
}

string Employee::get_firstName(){
  return firstName;
}

void Employee::set_lastName(string l){
  firstName = l;
}

string Employee::get_lastName(){
  return lastName;
}

void Employee::set_workingHours(float w){
  workingHours = w;
}

float Employee::get_workingHours(){
  return workingHours;
}

void Employee::set_costPerHour(float c){
  costPerHour = c;
}
    
float Employee::get_costPerHour(){
  return costPerHour;
}
    
void Employee::set_deduction(float d){
  deduction = d;
}

double Employee::get_deduction(){
  return deduction;
}

void Employee::set_annualSalary(double a){
  annualSalary = a;
}

double Employee::get_annualSalary(){
  return annualSalary;
}

