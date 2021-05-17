#include "Fleet.h"
#include "Vehicle/Car.h"
#include "Vehicle/Van.h"
#include "Vehicle/Truck.h"
#include "Vehicle/Bus.h"

void Fleet::addVehicle(Vehicle *&vehicle) {
    vehicles.push_back(vehicle);
}

void Fleet::addDriver(Driver *&driver) {
    drivers.push_back(driver);
}

int Fleet::getVehiclesAmount(VehicleType vehicleType) {
    int sum = 0;
    switch (vehicleType) {
        case CAR:
            for (Vehicle *vehicle : vehicles) {
                if (dynamic_cast<Car *>(vehicle)) {
                    sum++;
                }
            }
            break;
        case BUS:
            for (Vehicle *vehicle : vehicles) {
                if (dynamic_cast<Bus *>(vehicle)) {
                    sum++;
                }
            }
            break;
        case VAN:
            for (Vehicle *vehicle : vehicles) {
                if (dynamic_cast<Van *>(vehicle)) {
                    sum++;
                }
            }
            break;
        case TRUCK:
            for (Vehicle *vehicle : vehicles) {
                if (dynamic_cast<Truck *>(vehicle)) {
                    sum++;
                }
            }
            break;
        default:
            sum = (int) vehicles.size();
            break;
    }

    return sum;
}

int Fleet::getVehicleState(StatusType statusType) {
    int sum = 0;
    for (Vehicle *vehicle : vehicles) {
        if (vehicle->getStatusType() == statusType) {
            sum++;
        }
    }

    return sum;
}

int Fleet::getDriversAmount(bool onlyAvailable) {
    int sum = 0;
    if (!onlyAvailable) {
        return drivers.size();
    }

    for (Driver *driver : drivers) {
        if (driver->isAvailableStatus()) {
            sum++;
        }
    }

    return sum;
}

const vector<Vehicle *> &Fleet::getVehicles() const {
    return vehicles;
}

Vehicle *Fleet::getVehicleByPlate(string plate) {
    for (Vehicle *vehicle :vehicles) {
        if (plate == vehicle->getPlate()) {
            return vehicle;
        }
    }
    return nullptr;
}

vector<Driver *> Fleet::getDrivers(bool onlyAvailable) {
    if (!onlyAvailable) {
        return drivers;
    }

    vector<Driver *> driversList;

    for (Driver *driver :drivers) {
        if (driver->isAvailableStatus()) {
            driversList.push_back(driver);
        }
    }

    return driversList;
}

Driver *Fleet::getDriver(string driverId) {
    for (Driver *driver :drivers) {
        if (driver->getId() == driverId) {
            return driver;
        }
    }

    return nullptr;
}

void Fleet::deleteDriver(string driverId) {
    int index = 0;

    for (Driver *driver :drivers) {
        if (driver->getId() != driverId) {
            index++;
        } else {
            drivers.erase(drivers.begin() + index);
        }

    }
}

void Fleet::deleteVehicle(string plate) {
    int index = 0;

    for (Vehicle *vehicle :vehicles) {
        if (vehicle->getPlate() != plate) {
            index++;
        } else {
            vehicles.erase(vehicles.begin() + index);
        }

    }
}


