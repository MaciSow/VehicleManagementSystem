#include "Van.h"

Van::~Van() {

}

Van::Van(const string &plate,
         Status *status,
         const string &brand,
         const string &model,
         int capacity,
         bool isDoubleWheel,
         bool isSlideDoors,
         vector<Repair *> repairs,
         vector<Road *> roadRegister) {
    this->plate = plate;
    this->status = status;
    this->brand = brand;
    this->model = model;
    this->capacity = capacity;
    this->isDoubleWheel = isDoubleWheel;
    this->isSlideDoors = isSlideDoors;
    this->repairs = repairs;
    this->roadRegister = roadRegister;
}

void Van::log() {
    cout << "van" << endl;
    cout << plate << endl;
    cout << brand << endl;
    cout << model << endl;
    cout << capacity << endl;
    cout << isDoubleWheel << endl;
    cout << isSlideDoors << endl;
    status->log();
    for (Repair *repair: repairs) {
        repair->log();
    }

    for (Road *road: roadRegister) {
        road->log();
    }
}
