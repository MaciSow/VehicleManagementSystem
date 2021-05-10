#ifndef VEHICLEMENAGMENTSYSTEM_MAINCONTROLLER_H
#define VEHICLEMENAGMENTSYSTEM_MAINCONTROLLER_H

#include <typeinfo>
#include <iostream>

#include "../Model/Others/File.h"
#include "../Model/Fleet.h"
//#include "../View/ConsoleView.h"

using namespace std;

class MainController {
private:
    Fleet *fleet;
    File *f1;
    string path = "assets/";
    string filename = "Vehicles.yaml";
    Vehicle *selectedVehicle = nullptr;

public:
    Vehicle *getSelectedVehicle() const;

    void selectVehicle(string plate);

    void unselectVehicle();

    bool isCreating = false;

    MainController();

    void save(string filename);

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
};


#endif //VEHICLEMENAGMENTSYSTEM_MAINCONTROLLER_H
