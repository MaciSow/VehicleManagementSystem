#ifndef VEHICLEMENAGMENTSYSTEM_DRIVER_H
#define VEHICLEMENAGMENTSYSTEM_DRIVER_H

#include <string>
#include <iostream>

using namespace std;

class Driver {
public:
    Driver(const string &id, const string &name, const string &surname, bool isAvaliable);

    Driver(const string &name, const string &surname);

    void setId(const string &id);

    void log();

    virtual ~Driver();

    bool isAvailableStatus() const;

    string getFullName();

    const string &getId() const;

    void setAvailable(bool isAvailable = true);

private:
    string id;
    string name;
    string surname;
    bool isAvailable;
};

#endif //VEHICLEMENAGMENTSYSTEM_DRIVER_H