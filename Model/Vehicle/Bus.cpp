#include "Bus.h"

Bus::~Bus() {

}

Bus::Bus(const string &plate,
         Status *status,
         const string &brand,
         const string &model,
         int seatsAmount,
         bool isCoach,
         bool hasWC,
         vector<Repair *> repairs,
         vector<Road *> roadRegister) {
    this->plate = plate;
    this->status = status;
    this->brand = brand;
    this->model = model;
    this->seatsAmount = seatsAmount;
    this->isCoach = isCoach;
    this->hasWC = hasWC;
    this->repairs = repairs;
    this->roadRegister = roadRegister;
}

Bus::Bus(const string &plate, Status *status, const string &brand, const string &model, int seatsAmount, bool isCoach,
         bool hasWC) {
    this->plate = plate;
    this->status = status;
    this->brand = brand;
    this->model = model;
    this->seatsAmount = seatsAmount;
    this->isCoach = isCoach;
    this->hasWC = hasWC;
    vector<Repair *> repairs;
    vector<Road *> roadRegister;
    this->repairs = repairs;
    this->roadRegister = roadRegister;
}

void Bus::log() {
    cout << "bus" << endl;
    cout << plate << endl;
    cout << brand << endl;
    cout << model << endl;
    cout << seatsAmount << endl;
    cout << isCoach << endl;
    cout << hasWC << endl;
    status->log();
    for (Repair *repair: repairs) {
        repair->log();
    }

    for (Road *road: roadRegister) {
        road->log();
    }
}

VehicleType Bus::getVehicleType() {
    return BUS;
}

vector<string> Bus::getVehicleAllData() {
    vector<string> vehicleData = {model, brand, "", "", "", plate};
    vehicleData[2] = to_string(seatsAmount);
    vehicleData[3] = isCoach ? "Yes" : "No";
    vehicleData[4] = hasWC ? "Yes" : "No";
    vehicleData.push_back(status->getStatusName());

    return vehicleData;
}


