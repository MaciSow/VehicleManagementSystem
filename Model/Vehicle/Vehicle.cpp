#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Van.h"
#include "Truck.h"

Vehicle::Vehicle(const string &plate, Status *status, const string &brand, const string &model) : plate(plate),
                                                                                                  status(status),
                                                                                                  brand(brand),
                                                                                                  model(model) {}

Vehicle::Vehicle() {

}

Vehicle::~Vehicle() {
}

void Vehicle::log() {
    cout << "vehicle" << endl;
    cout << brand;
}

void Vehicle::addRepair(Repair *&repair) {
    repairs.push_back(repair);
}

void Vehicle::addRoad(Road *&road) {
    roadRegister.push_back(road);
}

StatusType Vehicle::getStatusType() {
    return status->getStatusType();
}

string Vehicle::getFullName() {
    return brand + " " + model;
}

Status *Vehicle::getStatus() const {
    return status;
}

const string &Vehicle::getPlate() const {
    return plate;
}

string Vehicle::getVehicleTypeName() {
    string vehicleType = "Unknown";

    if (dynamic_cast<Car *>(this)) {
        vehicleType = "Car";
    }

    if (dynamic_cast<Bus *>(this)) {
        vehicleType = "Bus";
    }

    if (dynamic_cast<Van *>(this)) {
        vehicleType = "Van";
    }

    if (dynamic_cast<Truck *>(this)) {
        vehicleType = "Truck";
    }
    return vehicleType;
}

vector<string> Vehicle::getVehicleAllData() {
    vector<string> vehicleData = {model, brand, "", "", "", plate, status->getStatusName()};
    return vehicleData;
}

vector<vector<string>> Vehicle::getRegisterData() {
    vector<vector<string>> registerData;

    for (Road *road: roadRegister) {
        registerData.push_back(road->getRoadData());
    }

    return registerData;
}

vector<vector<string>> Vehicle::getRepairsData() {
    vector<vector<string>> repairsData;

    for (Repair *repair: repairs) {
        repairsData.push_back(repair->getRepairData());
    }

    return repairsData;
}

void Vehicle::setStatus(Status *status) {
    this->status = status;
}

vector<string> Vehicle::getBasicPrintData() {
    vector<string> vehicleData;

    vehicleData.push_back("class: " + getVehicleTypeName());
    vehicleData.push_back("plate: " + plate);
    vehicleData.push_back("brand: " + brand);
    vehicleData.push_back("model: " + model);

    return vehicleData;
}

const vector<Repair *> &Vehicle::getRepairs() const {
    return repairs;
}

const vector<Road *> &Vehicle::getRoadRegister() const {
    return roadRegister;
}
