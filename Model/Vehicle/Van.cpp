#include "Van.h"

Van::~Van() {

}

Van::Van(const string &plate,
         Status *status,
         const string &brand,
         const string &model,
         int capacity,
         bool isDoubleWheel,
         bool isSlideDoors,
         vector<Repair *> repairs,
         vector<Road *> roadRegister) {
    this->plate = plate;
    this->status = status;
    this->brand = brand;
    this->model = model;
    this->capacity = capacity;
    this->isDoubleWheel = isDoubleWheel;
    this->isSlideDoors = isSlideDoors;
    this->repairs = repairs;
    this->roadRegister = roadRegister;
}

Van::Van(const string &plate, Status *status, const string &brand, const string &model, int capacity,
         bool isDoubleWheel, bool isSlideDoors) {
    this->plate = plate;
    this->status = status;
    this->brand = brand;
    this->model = model;
    this->capacity = capacity;
    this->isDoubleWheel = isDoubleWheel;
    this->isSlideDoors = isSlideDoors;
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
    cout << isDoubleWheel << endl;
    cout << isSlideDoors << endl;
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
    vehicleData[3] = isDoubleWheel ? "Yes" : "No";
    vehicleData[4] = isSlideDoors ? "Yes" : "No";
    vehicleData.push_back(status->getStatusName());

    return vehicleData;
}

void Van::updateAllData(vector<string> vehicleData) {
    this->plate = vehicleData[0];
    this->brand = vehicleData[1];
    this->model = vehicleData[2];
    this->capacity = stoi(vehicleData[3]);
    this->isDoubleWheel = vehicleData[4] == "Yes";
    this->isSlideDoors = vehicleData[5] == "Yes";
}


