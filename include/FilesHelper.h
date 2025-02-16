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

class FilesHelper {
private:
    static void saveLast(string fileName, int id) {
        ofstream file(fileName);
        file << id;
        file.close();
    }
public:
    static int getLast(string fileName) {
        ifstream file(fileName);
        int id = 0;
        if (file >> id) {
            file.close();
            return id;
        }
        file.close();
        return 0;
    }
    static void saveClient(Client c) {
        int id = getLast("ClientLastId.txt");
        fstream file;
        file.open("Clients.txt", ios::app);
        file << id + 1 << '&' << c.get_Name() << '&' << c.get_password() << '&' << c.get_balance() << endl;
        file.close();
        saveLast("ClientLastId.txt", id + 1);
    }
    static void saveEmployee(string fileName, string lastIdFile, Employee e) {
        int id = getLast(lastIdFile);
        fstream file;
        file.open(fileName, ios::app);
        file << id + 1 << '&' << e.get_Name() << '&' << e.get_password() << '&' << e.get_Salary() << endl;
        file.close();
        saveLast(lastIdFile, id + 1);

    }
    static void clearFile(string fileName, string lastIdFile) {
        ofstream file(fileName, ofstream::trunc);
        file.close();
        saveLast(lastIdFile, 0);
    }
};
