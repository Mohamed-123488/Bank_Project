#pragma once
#include "Person.h"

class Employee : public Person
{
// Attribute
private:
	double salary;
public:
// Constructor
	Employee()
	{
		salary = 0;
	}
	Employee(int id, string name, string password, double salary) :Person(id, name, password)
	{
		set_Salary(salary);
	}
// Setter
	void set_Salary(double salary)
	{
		if (Validation::validateSalary(salary))
		{
			this->salary = salary;
		}
		else
		{
			cout << "Invaild Salary" << endl;
		}
	}
// Getter
	double get_Salary()
	{
		return salary;
	}
// Method
	void display()
	{
		Person::display();
		cout << "Salary : " << salary << endl;
	}
};

