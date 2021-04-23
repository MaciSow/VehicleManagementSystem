#ifndef VEHICLEMENAGMENTSYSTEM_FLEET_H
#define VEHICLEMENAGMENTSYSTEM_FLEET_H

#include <vector>
#include <iostream>
#include "Vehicle/Vehicle.h"
#include "Driver.h"

using namespace std;

class Fleet {
private:
    vector<Vehicle *> vehicles;
    vector<Driver *> drivers;

public:
    void addVehicle(Vehicle *&vehicle);

    void addDriver(Driver *&driver);

    void log();
};


#endif //VEHICLEMENAGMENTSYSTEM_FLEET_H
