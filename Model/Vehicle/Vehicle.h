#ifndef VEHICLEMENAGMENTSYSTEM_VEHICLE_H
#define VEHICLEMENAGMENTSYSTEM_VEHICLE_H

#include <string>
#include <vector>
#include "../Status/Repair.h"
#include "../Status/Road.h"

using namespace std;

class Vehicle {
protected:
    string plate;
    string status;
    string brand;
    string model;
    vector<Repair> repairs;
    vector<Road> register;
public:
    Vehicle(const string &plate, const string &status, const string &brand, const string &model);

    virtual ~Vehicle();
};

#endif //VEHICLEMENAGMENTSYSTEM_VEHICLE_H
