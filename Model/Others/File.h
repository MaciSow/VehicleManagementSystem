#ifndef VEHICLEMENAGMENTSYSTEM_FILE_H
#define VEHICLEMENAGMENTSYSTEM_FILE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "../Fleet.h"
#include "../Vehicle/Car.h"
#include "../Status/Available.h"
#include "../Status/Broke.h"
#include "../Vehicle/Bus.h"
#include "../Vehicle/Truck.h"
#include "../Vehicle/Van.h"

using namespace std;

enum Type {
    CAR,
    BUS,
    VAN,
    TRUCK,
    ERROR
};

class File {
private:
    ifstream File;
    string nextLine;
public:
    void readVehiclesData(const string &fileName, Fleet *&fleet);

    void readDriversData(const string &fileName, Fleet *&fleet);

    static string cropValue(string line);

    static Type getClassNumber(string className);

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

    string saveData(Fleet *fleet, string fileName);
};

#endif //VEHICLEMENAGMENTSYSTEM_FILE_H
