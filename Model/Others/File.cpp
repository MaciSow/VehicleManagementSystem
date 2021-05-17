#include "File.h"


void File::readVehiclesData(const string &fileName, Fleet *&fleet) {

    FileRead.open(fileName, ios::in);

    if (!FileRead.is_open()) {
        cout << "Nie znaleziono pliku " << fileName << endl;
        return;
    }

    bool validClass = true;
    getline(FileRead, nextLine);
    Vehicle *vehicle;

    while (!FileRead.eof() && validClass && nextLine.length()) {
        if (nextLine.length() && nextLine.substr(0, 8) == "- class:") {
            string classType = cropValue(nextLine);

            switch (getClassNumber(classType)) {
                case CAR:
                    vehicle = readCar();
                    fleet->addVehicle(vehicle);
                    break;
                case BUS:
                    vehicle = readBus();
                    fleet->addVehicle(vehicle);
                    break;
                case VAN:
                    vehicle = readVan();
                    fleet->addVehicle(vehicle);
                    break;
                case TRUCK:
                    vehicle = readTruck();
                    fleet->addVehicle(vehicle);
                    break;
                default:
                    cout << "Invalid class" << endl;
                    validClass = false;
                    break;
            }

        } else {
            validClass = false;
        }
    }

    FileRead.close();
}

string File::cropValue(string line) {
    if (line.find(':') + 2 > line.length()) {
        return "";
    }
    line = line.substr(line.find(':') + 2);
    if (line[line.length() - 1] == '\r') {
        line.pop_back();
    }

    return line;
}

string File::getValue() {
    string txt;

    getline(FileRead, txt);
    txt = cropValue(txt);

    return txt;
}

VehicleType File::getClassNumber(string className) {

    if (className == "Car") {
        return CAR;
    }
    if (className == "Bus") {
        return BUS;
    }
    if (className == "Van") {
        return VAN;
    }
    if (className == "Truck") {
        return TRUCK;
    }
    return ANY;
}

StatusType File::getStatusNumber(string statusName) {
    if (statusName == "Available") {
        return AVAILABLE;
    }
    if (statusName == "Road") {
        return ROAD;
    }
    if (statusName == "Broke") {
        return BROKE;
    }
    if (statusName == "Repair") {
        return REPAIR;
    }
    return STATUSERROR;
}

Car *File::readCar() {
    vector<string> vehicleData = getNLines(6);

    Status *status = readStatus();

    vector<Repair *> repairs = readRepairs();

    vector<Road *> roadRegister = readRegister();

    Car *car = new Car(vehicleData[0], status, vehicleData[1], vehicleData[2], stoi(vehicleData[3]),
                       stoi(vehicleData[4]), vehicleData[5], repairs, roadRegister);
    return car;
}

Bus *File::readBus() {
    vector<string> vehicleData = getNLines(6);

    Status *status = readStatus();

    vector<Repair *> repairs = readRepairs();

    vector<Road *> roadRegister = readRegister();

    Bus *bus = new Bus(vehicleData[0], status, vehicleData[1], vehicleData[2], stoi(vehicleData[3]),
                       vehicleData[4] == "1", vehicleData[5] == "1", repairs, roadRegister);

    return bus;
}

Van *File::readVan() {
    vector<string> vehicleData = getNLines(6);

    Status *status = readStatus();

    vector<Repair *> repairs = readRepairs();

    vector<Road *> roadRegister = readRegister();

    Van *van = new Van(vehicleData[0], status, vehicleData[1], vehicleData[2], stoi(vehicleData[3]),
                       vehicleData[4] == "1", vehicleData[5] == "1", repairs, roadRegister);

    return van;
}

Truck *File::readTruck() {
    vector<string> vehicleData = getNLines(6);

    Status *status = readStatus();

    vector<Repair *> repairs = readRepairs();

    vector<Road *> roadRegister = readRegister();

    Truck *truck = new Truck(vehicleData[0], status, vehicleData[1], vehicleData[2], stoi(vehicleData[3]),
                             stoi(vehicleData[4]), vehicleData[5] == "1", repairs, roadRegister);

    return truck;
}

Status *File::readStatus() {
    getline(FileRead, nextLine);

    string statusType = getValue();
    string id;

    switch (getStatusNumber(statusType)) {
        case AVAILABLE:
            return new Available();
        case ROAD:
            id = getValue();
            getline(FileRead, nextLine);
            return readRoad(id);
        case BROKE:
            return readBroke();
        case REPAIR:
            getline(FileRead, nextLine);
            return readRepair();
        default:
            return nullptr;
    }
}

vector<string> File::getNLines(int count) {
    vector<string> vehicleData;
    for (int i = 0; i < count; ++i) {
        vehicleData.push_back(getValue());
    }

    return vehicleData;
}

Road *File::readRoad(string id) {
    int distance;

    Driver *driver = readShortDriver();

    if (id.length()) {
        driver->setId(id);
    }
    distance = stoi(getValue());

    Date *start = readDate();
    Date *end = readDate();

    return new Road(distance, driver, start, end);
}

Broke *File::readBroke() {
    string name = getValue();
    string description = getValue();
    return new Broke(name, description);
}

Driver *File::readShortDriver() {
    string name = cropValue(nextLine);
    string surname = getValue();
    return new Driver(name, surname);
}

Driver *File::readDriver() {
    string id = cropValue(nextLine);
    vector<string> driverData = getNLines(3);
    bool isAvailable = driverData[2] == "Available";
    return new Driver(id, driverData[0], driverData[1], isAvailable);
}

Date *File::readDate() {
    string dateString = getValue();
    return new Date(dateString);
}

Repair *File::readRepair() {
    string name = cropValue(nextLine);
    string description = getValue();
    Date *date = readDate();
    return new Repair(name, description, date);
}

vector<Repair *> File::readRepairs() {
    getline(FileRead, nextLine);
    getline(FileRead, nextLine);

    vector<Repair *> repairs;
    while (nextLine.substr(4, 7) == "- name:") {
        repairs.push_back(readRepair());
        getline(FileRead, nextLine);
    }

    return repairs;
}

vector<Road *> File::readRegister() {
    getline(FileRead, nextLine);

    vector<Road *> roadRegister;
    while (nextLine.length() && nextLine.substr(4, 7) == "- name:") {
        roadRegister.push_back(readRoad());
        getline(FileRead, nextLine);
    }
    return roadRegister;
}

void File::readDriversData(const string &fileName, Fleet *&fleet) {
    FileRead.open(fileName, ios::in);

    if (!FileRead.is_open()) {
        cout << "Nie znaleziono pliku " << fileName << endl;
        return;
    }

    bool validData = true;
    getline(FileRead, nextLine);
    Driver *driver;

    while (!FileRead.eof() && validData) {
        if (nextLine.substr(0, 5) == "- id:") {
            driver = readDriver();
            fleet->addDriver(driver);
            getline(FileRead, nextLine);
        } else {
            validData = false;
        }
    }
    FileRead.close();
}

void File::saveVehiclesData(string fileName, vector<Vehicle *> vehicles) {
    FilePrint = ofstream(fileName);

    if (FilePrint.is_open()) {
        for (Vehicle *vehicle: vehicles) {
            printVehicleData(vehicle);
            FilePrint << "  status:" << endl;
            printStatusData(vehicle->getStatus());
            FilePrint << "  repairs:" << endl;
            printRepairsData(vehicle->getRepairs());
            FilePrint << "  register:" << endl;
            printRegisterData(vehicle->getRoadRegister());
        }
        FilePrint.close();
        return;
    }

    cout << "Fail save data";
}

void File::saveDriversData(string fileName, vector<Driver *> drivers) {
    FilePrint = ofstream(fileName);

    if (FilePrint.is_open()) {
        for (Driver *driver: drivers) {
            vector<string> driverData = driver->getDriverPrintData();

            string separator = "- ";

            FilePrint << separator + *driverData.begin() << endl;

            separator = "  ";
            for (int i = 1; i < driverData.size(); i++) {
                FilePrint << separator + *(driverData.begin() + i) << endl;
            }
        }
        FilePrint.close();
        return;
    }

    cout << "Fail save data";
}

void File::printVehicleData(Vehicle *vehicle) {
    vector<string> vehicleBasicData = vehicle->getBasicPrintData();
    string separator = "- ";

    FilePrint << separator + *vehicleBasicData.begin() << endl;

    separator = "  ";
    for (int i = 1; i < vehicleBasicData.size(); i++) {
        FilePrint << separator + *(vehicleBasicData.begin() + i) << endl;
    }

    vector<string> vehicleSpecificData = vehicle->getSpecificPrintData();

    for (const string &row: vehicleSpecificData) {
        FilePrint << separator + row << endl;
    }
}

void File::printStatusData(Status *status) {
    vector<string> statusData = status->getStatusPrintData();
    string separator = "    ";

    for (const string &row: statusData) {
        FilePrint << separator + row << endl;
    }
}

void File::printRepairsData(vector<Repair *> repairs) {
    for (Repair *repair: repairs) {
        vector<string> repairData = repair->getStatusPrintData(true);
        string separator = "    - ";

        FilePrint << separator + *repairData.begin() << endl;

        separator = "      ";
        for (int i = 1; i < repairData.size(); i++) {
            FilePrint << separator + *(repairData.begin() + i) << endl;
        }
    }
}

void File::printRegisterData(vector<Road *> roadRegister) {
    for (Road *road: roadRegister) {
        vector<string> roadData = road->getStatusPrintData(true);
        string separator = "    - ";

        FilePrint << separator + *roadData.begin() << endl;

        separator = "      ";
        for (int i = 1; i < roadData.size(); i++) {
            FilePrint << separator + *(roadData.begin() + i) << endl;
        }
    }
}