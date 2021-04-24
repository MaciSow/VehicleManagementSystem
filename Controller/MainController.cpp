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
