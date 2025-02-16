#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
#include"DataSourceInterface.h"
#include"Parser.h"
#include"Person.h"
#include"FilesHelper.h"

class FileManager : public DataSourceInterface {
public:
    void addClient(Client c) override {
        FilesHelper::saveClient(c);
    }
    void addEmployee(Employee e) override {
        FilesHelper::saveEmployee("employees.txt", "lastEmployeeId.txt", e);
    }
    void addAdmin(Admin a) override {
        FilesHelper::saveEmployee("admins.txt", "lastAdminId.txt", a);
    }
    void getAllClients() override {}
    void getAllEmployees() override {}
    void getAllAdmins() override {}
    void removeAllClients() override {
        FilesHelper::clearFile("clients.txt", "lastClientId.txt");
    }
    void removeAllEmployees() override {
        FilesHelper::clearFile("employees.txt", "lastEmployeeId.txt");
    }
    void removeAllAdmins() override {
        FilesHelper::clearFile("admins.txt", "lastAdminId.txt");
    }
};
