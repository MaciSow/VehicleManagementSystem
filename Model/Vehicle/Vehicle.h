#ifndef VEHICLEMENAGMENTSYSTEM_VEHICLE_H
#define VEHICLEMENAGMENTSYSTEM_VEHICLE_H

#include "iostream"
#include <string>
#include <vector>
#include "../Status/Repair.h"
#include "../Status/Road.h"

using namespace std;

class Vehicle {
protected:
    string plate;
    Status *status;
    string brand;
    string model;
    vector<Repair *> repairs;
    vector<Road *> roadRegister;


public:
    Vehicle(const string &plate, Status *status, const string &brand, const string &model);

    Vehicle();

    virtual ~Vehicle();

    virtual void log() = 0;

    void addRepair(Repair *& repair);

    void addRoad(Road *& road);
};

#endif //VEHICLEMENAGMENTSYSTEM_VEHICLE_H
