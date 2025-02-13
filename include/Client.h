#pragma once
#include "Person.h"

class Client : public Person
{
// Attribute
private:
	double balance;
public:
// Constructor
	Client() :Person()
	{
		balance = 0;
	}
	Client(int id, string name, string password, double balance) : Person(id, name, password)
	{
		set_Balance(balance);
	}
// Setter
	void set_Balance(double balance)
	{
		if (Validation::validateBalance(balance))
		{
			this->balance = balance;
		}
		else
		{
			cout << "Invaild Balance" << endl;
		}
	}
//getter
	double get_balance()
	{
		return balance;
	}
// Method
	void deposit(double amount)
	{
		if (amount > 0)
		{
			this->balance += amount;
		}
	}
	void withdraw(double amount)
	{
		if (amount <= balance && amount > 0)
		{
			this->balance -= amount;
		}
	}
	void transferTo(double amount, Client& recipient)
	{
		withdraw(amount);
		recipient.deposit(amount);
	}
	void checkbalance()
	{
		cout << "Balance : " << balance << endl;
	}
	void display()
	{
		Person::display();
		cout << "Balance : " << balance << endl;
	}
};


