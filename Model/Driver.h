#ifndef VEHICLEMENAGMENTSYSTEM_DRIVER_H
#define VEHICLEMENAGMENTSYSTEM_DRIVER_H

#include <string>

using namespace std;

class Driver {
public:
    Driver(const string &id, const string &name, const string &surname, const string &status);

    virtual ~Driver();

private:
    string id;
    string name;
    string surname;
    string status;
};

#endif //VEHICLEMENAGMENTSYSTEM_DRIVER_H