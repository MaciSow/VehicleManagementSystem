#ifndef VEHICLEMENAGMENTSYSTEM_MAINCONTROLLER_H
#define VEHICLEMENAGMENTSYSTEM_MAINCONTROLLER_H

#include <typeinfo>
#include <iostream>

#include "../Model/Others/File.h"
#include "../Model/Fleet.h"

using namespace std;

class MainController {
private:
    Fleet *fleet;
    File *f1;
    string path = "assets/";
    string vehiclesDataFilename = "Vehicles.yaml";
    string driversDataFilename = "Drivers.yaml";

    Vehicle *selectedVehicle = nullptr;
    Driver *selectedDriver = nullptr;
public:
    Vehicle *getSelectedVehicle() const;

    void selectVehicle(string plate);

    void unselectVehicle();

    Driver *getSelectedDriver() const;

    void selectDriver(string driverId);

    void unselectDriver();

    bool isCreating = false;

    MainController();

    void save();

    void clean();

    vector<int> getStateData();

    vector<vector<string>> getVehiclesList();

    void createVehicle(vector<string> vehicleData, VehicleType vehicleType);

    void editVehicle(vector<string> vehicleData);

    void setAvailable(bool isNow);

    void setRoad(int distance, int pause, string driverId);

    vector<vector<string>> getDriversList(bool onlyAvailable = false);

    void setBroke(string name, string description);

    void setRepair(int takeTime);

    void createDriver(string name, string surname);

    void editDriver(string name, string surname);
};


#endif //VEHICLEMENAGMENTSYSTEM_MAINCONTROLLER_H
