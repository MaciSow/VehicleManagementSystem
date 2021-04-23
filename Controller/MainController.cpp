#include <iostream>
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