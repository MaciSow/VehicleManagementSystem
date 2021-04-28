#include "Truck.h"

Truck::~Truck() {

}

Truck::Truck(const string &plate,
             Status *status,
             const string &brand,
             const string &model,
             int capacity,
             int axisAmount,
             bool hasTrailer,
             vector<Repair *> repairs,
             vector<Road *> roadRegister) {
    this->plate = plate;
    this->status = status;
    this->brand = brand;
    this->model = model;
    this->capacity = capacity;
    this->axisAmount = axisAmount;
    this->hasTrailer = hasTrailer;
    this->repairs = repairs;
    this->roadRegister = roadRegister;
}

void Truck::log() {
    cout << "truck" << endl;
    cout << plate << endl;
    cout << brand << endl;
    cout << model << endl;
    cout << capacity << endl;
    cout << axisAmount << endl;
    cout << hasTrailer << endl;
    status->log();
    for (Repair *repair: repairs) {
        repair->log();
    }

    for (Road *road: roadRegister) {
        road->log();
    }
}

VehicleType Truck::getVehicleType() {
    return TRUCK;
}

vector<string> Truck::getVehicleAllData() {
    vector<string> vehicleData = {model, brand, "", "", "", plate};
    vehicleData[2] = to_string(capacity) + " kg";
    vehicleData[3] = to_string(axisAmount);
    vehicleData[4] = hasTrailer ? "Yes" : "No";
    vehicleData.push_back(status->getStatusName());

    return vehicleData;
}
