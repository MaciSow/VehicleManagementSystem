#ifndef VEHICLEMENAGMENTSYSTEM_FLEET_H
#define VEHICLEMENAGMENTSYSTEM_FLEET_H

#include <vector>
#include <iostream>
#include "Vehicle/Vehicle.h"
#include "Driver.h"
#include "Others/VehicleType.h"

using namespace std;

class Fleet {
private:
    vector<Vehicle *> vehicles;
    vector<Driver *> drivers;

public:
    void addVehicle(Vehicle *&vehicle);

    void addDriver(Driver *&driver);

    void log();

    int getVehiclesAmount(VehicleType vehicleType = ANY);

    int getVehicleState(StatusType statusType = AVAILABLE);

    int getDriversAmount(bool onlyAvailable = false);

    const vector<Vehicle *> &getVehicles() const;

    Vehicle* getVehicleByPlate(string plate);
};


#endif //VEHICLEMENAGMENTSYSTEM_FLEET_H
