#include "Fleet.h"

void Fleet::addVehicle(Vehicle *&vehicle) {
    vehicles.push_back(vehicle);
}

void Fleet::addDriver(Driver *&driver) {
    drivers.push_back(driver);
}

void Fleet::log() {
    cout << vehicles.size() << endl;
    cout << drivers.size() << endl;
//    for (Driver *driver: drivers) {
//        driver->log();
//    }

//    for (int i = 0; i < vehicles.size(); ++i) {
//         vehicles[i]->log();
//    }

}
