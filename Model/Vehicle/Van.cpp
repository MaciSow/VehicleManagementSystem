#include "Van.h"

Van::~Van() {

}

Van::Van(const string &plate,
         Status *status,
         const string &brand,
         const string &model,
         int capacity,
         bool hasDoubleWheel,
         bool hasSlideDoors,
         vector<Repair *> repairs,
         vector<Road *> roadRegister) {
    this->plate = plate;
    this->status = status;
    this->brand = brand;
    this->model = model;
    this->capacity = capacity;
    this->hasDoubleWheel = hasDoubleWheel;
    this->hasSlideDoors = hasSlideDoors;
    this->repairs = repairs;
    this->roadRegister = roadRegister;
}

Van::Van(const string &plate, Status *status, const string &brand, const string &model, int capacity,
         bool hasDoubleWheel, bool hasSlideDoors) {
    this->plate = plate;
    this->status = status;
    this->brand = brand;
    this->model = model;
    this->capacity = capacity;
    this->hasDoubleWheel = hasDoubleWheel;
    this->hasSlideDoors = hasSlideDoors;
    vector<Repair *> repairs;
    vector<Road *> roadRegister;
    this->repairs = repairs;
    this->roadRegister = roadRegister;
}

void Van::log() {
    cout << "van" << endl;
    cout << plate << endl;
    cout << brand << endl;
    cout << model << endl;
    cout << capacity << endl;
    cout << hasDoubleWheel << endl;
    cout << hasSlideDoors << endl;
    status->log();
    for (Repair *repair: repairs) {
        repair->log();
    }

    for (Road *road: roadRegister) {
        road->log();
    }
}

VehicleType Van::getVehicleType() {
    return VAN;
}

vector<string> Van::getVehicleAllData() {
    vector<string> vehicleData = {brand, model, "", "", "", plate};
    vehicleData[2] = to_string(capacity);
    vehicleData[3] = hasDoubleWheel ? "Yes" : "No";
    vehicleData[4] = hasSlideDoors ? "Yes" : "No";
    vehicleData.push_back(status->getStatusName());

    return vehicleData;
}

void Van::updateAllData(vector<string> vehicleData) {
    this->plate = vehicleData[0];
    this->brand = vehicleData[1];
    this->model = vehicleData[2];
    this->capacity = stoi(vehicleData[3]);
    this->hasDoubleWheel = vehicleData[4] == "Yes";
    this->hasSlideDoors = vehicleData[5] == "Yes";
}

vector<string> Van::getSpecificPrintData() {
    vector<string> vehicleData;

    vehicleData.push_back("capacity: " + to_string(capacity));
    vehicleData.push_back("doubleWheel: " + to_string(hasDoubleWheel ? 1 : 0));
    vehicleData.push_back("slideDoors: " + to_string(hasSlideDoors ? 1 : 0));

    return vehicleData;
}


