#ifndef VEHICLEMENAGMENTSYSTEM_FILE_H
#define VEHICLEMENAGMENTSYSTEM_FILE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "VehicleType.h"
#include "../Fleet.h"
#include "../Vehicle/Car.h"
#include "../Status/Available.h"
#include "../Status/Broke.h"
#include "../Vehicle/Bus.h"
#include "../Vehicle/Truck.h"
#include "../Vehicle/Van.h"

using namespace std;

class File {
private:
    ifstream FileRead;
    ofstream FilePrint;
    string nextLine;
public:
    void readVehiclesData(const string &fileName, Fleet *&fleet);

    void readDriversData(const string &fileName, Fleet *&fleet);

    static string cropValue(string line);

    static VehicleType getClassNumber(string className);

    static StatusType getStatusNumber(string statusName);

    Car *readCar();

    Bus *readBus();

    Van *readVan();

    Truck *readTruck();

    Date *readDate();

    Status *readStatus();

    Road *readRoad(string id = "");

    Broke *readBroke();

    Repair *readRepair();

    vector<Repair *> readRepairs();

    vector<Road *> readRegister();

    Driver *readShortDriver();

    Driver *readDriver();

    string getValue();

    vector<string> getNLines(int count);

    void saveVehiclesData(string fileName, vector<Vehicle *> vehicles);

    void printVehicleData(Vehicle *vehicle);

    void printStatusData(Status *status);

    void printRepairsData(vector<Repair *> repairs);

    void printRegisterData(vector<Road *> roadRegister);

    void saveDriversData(string fileName, vector<Driver *> drivers);
};

#endif //VEHICLEMENAGMENTSYSTEM_FILE_H
