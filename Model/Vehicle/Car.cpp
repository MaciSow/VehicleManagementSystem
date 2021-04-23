#include "Car.h"

//Car::Car(const string &plate, const string &status, const string &brand, const string &model, int seatsAmount,
//         int doorsAmount, const string &bodyStyle) :Vehicle(plate, status, brand, model),
//                                                    PeopleTransport(plate, status, brand, model, seatsAmount),
//                                                    doorsAmount(doorsAmount), bodyStyle(bodyStyle) {
//
//}

//Car::Car(const string &plate1, const string &status1, const string &brand1, const string &model1,
//         const string &plate, const string &status, const string &brand, const string &model, int seatsAmount,
//         int doorsAmount, const string &bodyStyle) : Vehicle(plate1, status1, brand1, model1),
//                                                     PeopleTransport(plate, status, brand, model, seatsAmount),
//                                                     doorsAmount(doorsAmount), bodyStyle(bodyStyle) {
//
//}


Car::Car(const string &plate, Status *status, const string &brand, const string &model, int seatsAmount,
         int doorsAmount, const string &bodyStyle, vector<Repair *> repairs, vector<Road *> roadRegister) {
    this->plate = plate;
    this->status = status;
    this->brand = brand;
    this->model = model;
    this->seatsAmount = seatsAmount;
    this->doorsAmount = doorsAmount;
    this->bodyStyle = bodyStyle;
    this->repairs = repairs;
    this->roadRegister = roadRegister;
}

Car::~Car() {

}


void Car::log() {
    cout << "car" << endl;
    cout << plate << endl;
    cout << brand << endl;
    cout << model << endl;
    cout << seatsAmount << endl;
    cout << doorsAmount << endl;
    cout << bodyStyle << endl;
    status->log();
    for (Repair *repair: repairs) {
        repair->log();
    }

    for (Road *road: roadRegister) {
        road->log();
    }
}
