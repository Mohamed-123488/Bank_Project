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
public:
 // Constructor
    Person() {
        Id = 0 ;
        Password = "";
        Name = "";
    }
    Person(int i , string n, string p) {
        Id = i;
        Name = n;
        Password = p;
    }
 // Setter
    void setId(int i) {
        Id = i;
    }
    void setName(string n) {
        Name = n;
    }
    void setPassword(string p) {
        Password = p;
    }
 // Getter
    int getId() {
        return Id;
    }
    string getName() {
        return Name;
    }
    string getPassword() {
        return Password;
    }
};

// Class Client Inheritance From Class Person

class Client : public Person
{
// Attribute
private:
    int Id = 0;
    string Name;
    string Password;
    double Balance = 0;

    bool isAlphabetic (const string &str) {
        for (const char ch: str) {
            if (!isalpha(ch)) {
                return false;
            }
        }

    }

public:
// Constructor
    Client()
    {
        Id = 0;
        Name = " ";
        Password = " ";
        Balance = 0;
    }
    Client(const int i, const string &n , const string &p , const double b)
    {
        Id = i;
        Name = n;
        Password = p;
        Balance = b;
    }
// Setter
    void set_Id(const int i)
    {
        Id = i;
    }
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

 // If The Balance Is Less Than 1500 , Print Balance OtherWise , Exit .

    void set_Balance(const double newBalance)
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
    int get_Id()

    const { return Id ;}

    string get_Name()
    {
        return Name;
    }
    string get_Password() {
        return Password;
    }
    double get_Balance()

    const{return Balance;}

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
        cout<< " Client ID : " << Id <<endl;
        cout<<"**********************************"<<endl;
        cout << " Name : " << Name <<endl;
        cout<<"**********************************"<<endl;
        cout << " Password : " << Password <<endl;
        cout<<"**********************************"<<endl;
        cout << " Balance : " << Balance <<endl;
        cout<<"**********************************"<<endl;
    }
};

int main()
{
    Client client1 (2 , "Mohamed" , "nmj 2254" , 1500);
    Client client2 (3 , "Ahmed" , "MO 2214" , 1200 );

    client1.display();
    cout<<"**************"<<endl;
    client1.deposit(400);
    cout<<"****************"<<endl;
    client1.withdraw(600);
    cout<<"****************"<<endl;
    client1.transferTo(800, client2);
    cout<<"****************"<<endl;
    client1.checkBalance();
     return 0;
}
