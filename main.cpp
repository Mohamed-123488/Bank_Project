#include <iostream>
#include <string>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

int main()
{
	Person p1(2, "Mohamed", "Mo2254258");
	p1.display();
	cout << "****************" << endl;
	Client c1(2, "Ahmed A", "Mo2254369",1800);
	cout << "****************" << endl;
	Client c2(3, "Yosuf A", "Qe55871458", 1900);
	cout << "****************" << endl;
	c1.display();
	cout << "****************" << endl;
	c1.deposit(500);
	cout << "****************" << endl;
	c1.withdraw(800);
	cout << "****************" << endl;
	c1.transferTo(600,c2);
	cout << "****************" << endl;
	c1.checkbalance();
	cout << "****************" << endl;

	Employee e1(1, "Retaj A", "Kj2589852", 6000);
	e1.display();
	cout << "****************" << endl;
	Admin a1(1, "Maryam A", "Kv25899875", 15000);
	a1.display();



}
