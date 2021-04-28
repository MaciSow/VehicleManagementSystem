#include "MainController.h"


MainController::MainController() {

    fleet = new Fleet();
    f1 = new File();
    f1->readVehiclesData(path + filename, fleet);

    f1 = new File();
    filename = "Drivers.yaml";
    f1->readDriversData(path + filename, fleet);

    fleet->log();
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
        row.push_back(vehicle->getPlate());
        row.push_back(vehicle->getFullName());
        row.push_back(vehicle->getVehicleTypeName());
        row.push_back(vehicle->getStatus()->getStatusName());

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