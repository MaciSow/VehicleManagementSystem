#include "MainController.h"

MainController::MainController() {

    fleet = new Fleet();
    vehiclesFile = new File();
    vehiclesFile->readVehiclesData(path + vehiclesDataFilename, fleet);

    driversFile = new File();
    driversFile->readDriversData(path + driversDataFilename, fleet);
}

void MainController::save() {
    vehiclesFile->saveVehiclesData(path + vehiclesDataFilename, fleet->getVehicles());

    driversFile->saveDriversData(path + driversDataFilename, fleet->getDrivers());
}

void MainController::clean() {

}

vector<int> MainController::getStateData() {
    vector<int> stateData;
    stateData.push_back(fleet->getVehiclesAmount());
    stateData.push_back(fleet->getVehiclesAmount(CAR));
    stateData.push_back(fleet->getVehiclesAmount(BUS));
    stateData.push_back(fleet->getVehiclesAmount(VAN));
    stateData.push_back(fleet->getVehiclesAmount(TRUCK));

    stateData.push_back(fleet->getVehicleState(AVAILABLE));
    stateData.push_back(fleet->getVehicleState(ROAD));
    stateData.push_back(fleet->getVehicleState(REPAIR));

    stateData.push_back(fleet->getDriversAmount(false));
    stateData.push_back(fleet->getDriversAmount(true));

    return stateData;
}

vector<vector<string>> MainController::getVehiclesList() {
    vector<vector<string>> vehicleList;

    for (Vehicle *vehicle: fleet->getVehicles()) {
        vector<string> row;
        row.push_back(vehicle->getFullName());
        row.push_back(vehicle->getVehicleTypeName());
        row.push_back(vehicle->getStatus()->getStatusName());
        row.push_back(vehicle->getPlate());

        vehicleList.push_back(row);
    }

    return vehicleList;
}

void MainController::selectVehicle(string plate) {
    selectedVehicle = fleet->getVehicleByPlate(plate);
}

Vehicle *MainController::getSelectedVehicle() const {
    return selectedVehicle;
}

void MainController::createVehicle(vector<string> vehicleData, VehicleType vehicleType) {
    Vehicle *vehicle;
    Status *status = new Available();

    switch (vehicleType) {
        case CAR:
            vehicle = new Car(
                    vehicleData[0],
                    status,
                    vehicleData[1],
                    vehicleData[2],
                    stoi(vehicleData[3]),
                    stoi(vehicleData[4]),
                    vehicleData[5]
            );
            break;
        case BUS:
            vehicle = new Bus(
                    vehicleData[0],
                    status,
                    vehicleData[1],
                    vehicleData[2],
                    stoi(vehicleData[3]),
                    vehicleData[4] == "Yes",
                    vehicleData[5] == "Yes"
            );
            break;
        case VAN:
            vehicle = new Van(
                    vehicleData[0],
                    status,
                    vehicleData[1],
                    vehicleData[2],
                    stoi(vehicleData[3]),
                    vehicleData[4] == "Yes",
                    vehicleData[5] == "Yes"
            );
            break;
        case TRUCK:
            vehicle = new Truck(
                    vehicleData[0],
                    status,
                    vehicleData[1],
                    vehicleData[2],
                    stoi(vehicleData[3]),
                    stoi(vehicleData[4]),
                    vehicleData[5] == "Yes"
            );
            break;
        default:
            break;
    }

    fleet->addVehicle(vehicle);
}

void MainController::unselectVehicle() {
    selectedVehicle = nullptr;
}

void MainController::editVehicle(vector<string> vehicleData) {
    selectedVehicle->updateAllData(vehicleData);
}


void MainController::setAvailable(bool isNow) {
    Status *status = selectedVehicle->getStatus();
    Road *road = dynamic_cast<Road *>(status);

    if (isNow) {
        road->setEndDate(new Date());
    } else {
        road->setReturn();
    }

    selectedVehicle->addRoad(road);
    selectedVehicle->setStatus(new Available());
}

vector<vector<string>> MainController::getDriversList(bool onlyAvailable) {
    vector<vector<string>> driversList;

    for (Driver *driver:fleet->getDrivers(onlyAvailable)) {
        vector<string> row;
        row.push_back(driver->getFullName());

        if (!onlyAvailable) {
            row.push_back(driver->getStatusName());
        }

        row.push_back(driver->getId());

        driversList.push_back(row);
    };

    return driversList;
}

void MainController::setRoad(int distance, int pause, string driverId) {
    Driver *driver = fleet->getDriver(driverId);
    driver->setAvailable(false);

    Status *status = new Road(distance, driver, pause);
    selectedVehicle->setStatus(status);
}

void MainController::setRepair(int takeTime) {
    Status *status = selectedVehicle->getStatus();
    vector<string> statusData = status->getData();

    Date *fixDate = new Date();
    fixDate->addDays(takeTime);

    Repair *repair = new Repair(statusData[0], statusData[1], fixDate);

    if (!takeTime) {
        selectedVehicle->addRepair(repair);
        selectedVehicle->setStatus(new Available());
        return;
    }
    selectedVehicle->setStatus(repair);
}

void MainController::setBroke(string name, string description) {
    Status *status = selectedVehicle->getStatus();

    if (Road *road = dynamic_cast<Road *>(status)) {
        road->setEndDate(new Date());
        selectedVehicle->addRoad(road);
    }

    Broke *broke = new Broke(name, description);
    selectedVehicle->setStatus(broke);
    return;
}

Driver *MainController::getSelectedDriver() const {
    return selectedDriver;
}

void MainController::selectDriver(string driverId) {
    selectedDriver = fleet->getDriver(driverId);
}

void MainController::unselectDriver() {
    selectedDriver = nullptr;
}

void MainController::createDriver(string name, string surname) {
    Driver *driver = new Driver(name, surname, true);
    fleet->addDriver(driver);
    selectedDriver = driver;
}

void MainController::editDriver(string name, string surname) {
    selectedDriver->setName(name);
    selectedDriver->setSurname(surname);
}

void MainController::deleteDriver() {
    fleet->deleteDriver(selectedDriver->getId());
    unselectDriver();
}

void MainController::deleteVehicle() {
    fleet->deleteVehicle(selectedVehicle->getPlate());
    unselectVehicle();
}
