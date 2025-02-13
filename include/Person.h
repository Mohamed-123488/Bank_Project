#pragma once
#include<iostream>
#include "Validation.h"
using namespace std;
class Person {
    // Attribute
private:
    int id;
    string name;
    string password;
public:
    // Constructor
    Person()
    {
        id = 0;
        name = " ";
        password = " ";
    }
    Person(int id, string password, string name)
    {
        set_ID(id);
        set_Name(name);
        set_password(password);
    }
    // Setter
    void set_Name(string name)
    {
        if (Validation::validatename(name))
        {
            this->name = name;
        }
        else
        {
            cout << "Invalid Name" << endl;
        }

    }
    void set_password(string password)
    {
        if (Validation::validatepassword(password))
        {
            this->password = password;
        }
        else
        {
            cout << "Invalid Password" << endl;
        }
    }
    void set_ID(int id)
    {
        this->id = id;
    }
    // Getter
    string get_Name()
    {
        return this->name;
    }
    string get_password()
    {
        return this->password;
    }
    int get_ID()
    {
        return this->id;
    }
    // Method
    void display() {
        cout << " ID : " << id << endl;
        cout << "Name : " << name << endl;
        cout << "Password : " << password << endl;
    }
};
