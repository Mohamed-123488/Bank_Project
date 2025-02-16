#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
#include"DataSourceInterface.h"

class Parser {
private:

    static vector<string> split(string line) {
        stringstream stream(line);
        string token;
        vector<string> info;
        while (getline(stream, token, "&"))
            info.push_back(token);
        return info;
    }
public:

    static Client parseToClient(string line) {
        vector<string> info = split(line);
        Client client;
        client.set_ID (stoi(info[0]));
        client.set_Name  (info[1]);
        client.set_password  (info[2]);
        client.set_Balance  (stod(info[3]));
        return client;
    }
    static Employee parseToEmployee(string line) {
        vector<string> info = split(line);
        Employee employee;
        employee.set_ID  (stoi(info[0]));
        employee.set_Name  (info[1]);
        employee.set_password (info[2]);
        employee.set_Salary (stod(info[3]));
        return employee;
    }
    static Admin parseToAdmin(string line) {
        vector<string> info = split(line);
        Admin admin;
        admin.set_ID(stoi(info[0]));
        admin.set_Name(info[1]);
        admin.set_password(info[2]);
        admin.set_Salary(stod(info[3]));
        return admin;
    }
};
