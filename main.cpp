///**************  Bank System *************///

#include <iostream>
#include <string>
using namespace std;
class Person
{
 // Attribute
protected:
    int Id = 0;
    string Name;
    string Password;

    bool isAlphabetic (const string &str)
    {
        for (const char ch: str)
        {
            if (!isalpha(ch))
            {
                return false;
            }
        }

    }

public:
 // Constructor
    Person()
    {
        Id = 0 ;
        Password = "";
        Name = "";
    }
    Person(int i , string n, string p)
    {
        Id = i;
        Name = n;
        Password = p;
    }

 // Setter

   void set_Name(const string &newName )
    {
        if (newName.length() >= 5 && newName.length() <= 20 && isAlphabetic(newName))
        {
            Name = newName;
        }
        else
        {
            cout<<"Name must be alphabetic and between 5 and 20 characters."<<endl;
        }
    }

// If The Password Between (Min Size 8 $$ Max Size 20) , OtherWise Exit .

    void set_Password (const string &newPassword)
    {
        if (newPassword.length() >= 8 && newPassword.length() <= 20)
        {
            Password = newPassword;
        }
        else
        {
            cout<< "Password must be alphabetic and less than 8 characters."<<endl;
        }
    }
 // Getter

    string getName()
    {
        return Name;
    }
    string getPassword()
    {
        return Password;
    }

    virtual void display()
    {
        cout<<"ID : "<<id<<" Name : "<<name<<endl;
    }
};

// Class Client Inheritance From Class Person

class Client : public Person
{
// Attribute
protected:

    double Balance = 0;

public:
// Constructor
    Client(int i, string n ,  string p , double b) : Person (id ,name ,password)
    {
        Balance = b;
    }

 //Setter

 // If The Balance Is Less Than 1500 , Print Balance OtherWise , Exit .

    void set_Balance( double newBalance)
    {
        if (newBalance >= 1500)
        {
            Balance = newBalance;
        }
        else
        {
            cout<<"Balance must be greater than 1500."<<endl;
        }
    }

// Getter

    double get_Balance()

    {
        return Balance;
    }

//*********************************** Functions ***************************//

// Deposit Function
    void deposit(const double amount)
    {
        if (amount >0)
        {
            Balance += amount;
            cout << "Balance : " << amount << " . new Balance " << Balance <<endl;
        }
        else
        {
            cout<<"Deposit amount must be positive"<<endl;
        }
    }

// Withdraw Function
    void withdraw(const double amount)
    {
        if (amount > 0 && amount < Balance)
        {
            Balance -= amount;
            cout << "Withdraw : " << amount << " . new Balance " << Balance <<endl;
        }
        else
        {
            cout << " Invalid Withdraw Amount "<<endl;
        }
    }

// Transfer to Function
    void transferTo (const double amount, Client & recipient) {
        if (amount > 0 && Balance - amount >=1500)
        {
            Balance -= amount;
            recipient.deposit(amount);
            cout << "Transfer To : " << amount << " to " << recipient.get_Name() << " . New Balance :" << Balance <<endl;
        }
        else
        {
            cout <<" In Valid Transfer Amount "<<endl;
        }
    }

// Check Balance Function
    void checkBalance() const
    {
        cout << " Current Balance : " << Balance <<endl;
    }
// Display Function
    void display()
    {
        cout << " Balance : " << Balance <<endl;
        cout<<"**********************************"<<endl;
    }
};

// class Employee Inheritance From Person.

class Employee : public Person
{
// Attribute
protected:
     double Salary;
public:
// Constructor
        Employee(int id , string name , string Password , double Salary) : Person (id , name , password)
        {
            Salary = 0;
        }

//Setter

// If The Balance Is Less Than 5000 , Print Balance OtherWise , Exit .

    void set_Salary(const double newSalary)
    {
        if (newSalary < 5000)
        {
            Salary = newSalary;
        }
        else
        {
            cout<<"Salary must be greater than 5000."<<endl;
        }
    }

// Getter

    double get_Salary()
    {
        return Salary;
    }

// Function

void display()
{
    Person::display();
    cout<<"Salary : "<<Salary<<endl;
}
};

// Class Admin Inheritance From Person

class Admin : public Employee
{
// Attribute
public:
//Constructor
Admin(int id, string name, string password, double salary) : Employee (id, name, password, salary)
{}

// Function Display

void display()
    {
        Person::display();
        cout << "Admin Salary: " << salary << endl;
    }

};

int main()
{
     Client client1(1, "Mohamed Atef", "Mo 2005", 2000);
    Employee emp1(2, "Omar Ramadan", "Om 2006", 6000);
    Admin admin1(3, "Ahmed", "Ah 2015", 7000);

    client1.display();
    emp1.display();
    admin1.display();
     return 0;
}
