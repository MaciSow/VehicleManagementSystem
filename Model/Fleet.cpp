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


