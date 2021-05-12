#ifndef VEHICLEMENAGMENTSYSTEM_DRIVER_H
#define VEHICLEMENAGMENTSYSTEM_DRIVER_H

#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Driver {
public:
    Driver(const string &id, const string &name, const string &surname, bool isAvailable);

    Driver(const string &name, const string &surname, bool isAvailable);

    Driver(const string &name, const string &surname);

    void setId(const string &id);

    void log();

    virtual ~Driver();

    bool isAvailableStatus() const;

    string getFullName();

    const string &getId() const;

    void setAvailable(bool isAvailable = true);

    vector<string> getAllData();

    string getStatusName();

    string getStatusTypeName();

    void setName(const string &name);

    void setSurname(const string &surname);

    vector<string> getDriverPrintData();

private:
    string id;
    string name;
    string surname;
    bool isAvailable;

    void generateId();
};

#endif //VEHICLEMENAGMENTSYSTEM_DRIVER_H