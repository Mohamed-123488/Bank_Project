#pragma once
#include "Employee.h"
class Admin : public Employee
{
public:
	Admin() :Employee()
	{

	}
	Admin(int id, string name, string password, double salary) :Employee(id , name , password, salary)
	{

	}

};

