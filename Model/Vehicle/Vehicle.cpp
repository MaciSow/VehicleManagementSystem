#include "Vehicle.h"

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



