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
    vector<string> vehicleData = {brand, model, "", "", "", plate};
    vehicleData[2] = to_string(seatsAmount);
    vehicleData[3] = isCoach ? "Yes" : "No";
    vehicleData[4] = hasWC ? "Yes" : "No";
    vehicleData.push_back(status->getStatusName());

    return vehicleData;
}

void Bus::updateAllData(vector<string> vehicleData) {
    this->plate = vehicleData[0];
    this->brand = vehicleData[1];
    this->model = vehicleData[2];
    this->seatsAmount = stoi(vehicleData[3]);
    this->isCoach = vehicleData[4] == "Yes";
    this->hasWC = vehicleData[5] == "Yes";
}

vector<string> Bus::getSpecificPrintData() {
    vector<string> vehicleData;

    vehicleData.push_back("seats: " + to_string(seatsAmount));
    vehicleData.push_back("coach: " + to_string(isCoach ? 1 : 0));
    vehicleData.push_back("wc: " + to_string(hasWC ? 1 : 0));

    return vehicleData;
}


