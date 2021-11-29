#ifndef HRM_H
#define HRM_H
#include "employee.h"

class HRM{
  public:
    Employee emp[100];
    int size = 0;
    int addEmployee();
    int deleteEmployee();
    int updateEmployee();
    int searchEmployee();
};

#endif