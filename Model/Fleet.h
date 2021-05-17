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

    int getVehiclesAmount(VehicleType vehicleType = ANY);

    int getVehicleState(StatusType statusType = AVAILABLE);

    int getDriversAmount(bool onlyAvailable = false);

    const vector<Vehicle *> &getVehicles() const;

    Vehicle* getVehicleByPlate(string plate);

    vector<Driver *> getDrivers(bool onlyAvailable = false);

    Driver * getDriver(string driverId);

    void deleteDriver(string driverId);

    void deleteVehicle(string plate);
};


#endif //VEHICLEMENAGMENTSYSTEM_FLEET_H
