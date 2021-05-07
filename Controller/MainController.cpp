#include "MainController.h"


MainController::MainController() {

    fleet = new Fleet();
    f1 = new File();
    f1->readVehiclesData(path + filename, fleet);

    f1 = new File();
    filename = "Drivers.yaml";
    f1->readDriversData(path + filename, fleet);

//    fleet->log();

    cout << fleet->getVehicles()[1]->getRegisterData().size();

}

void MainController::save(string filename) {
//	if (filename == "") {
//		filename = this->filename;
//	}
//	f1->saveData(list, path + filename);
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

vector<vector<string>> MainController::getVehicleList() {
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

void MainController::setSelectedVehicle(string plate) {
    selectedVehicle = fleet->getVehicleByPlate(plate);
}

Vehicle *MainController::getSelectedVehicle() const {
    return selectedVehicle;
}

void MainController::createVehicle(vector<string> vehicleData, VehicleType vehicleType) {
    Vehicle *vehicle;
    Status *status = new Status(AVAILABLE);

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
