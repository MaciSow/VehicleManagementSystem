#include "File.h"


void File::readVehiclesData(const string &fileName, Fleet *&fleet) {

    File.open(fileName, ios::in);

    if (!File.is_open()) {
        cout << "Nie znaleziono pliku " << fileName << endl;
        return;
    }

    bool validClass = true;
    getline(File, nextLine);
    Vehicle *vehicle;

    while (!File.eof() && validClass && nextLine.length()) {
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
//        cout << nextLine << endl;
//        auto *vehicle = new Vehicle("dfs", "dsada", "sad", "were");
//        fleet->addVehicle(vehicle);

//        fleet->log();
    }

    File.close();
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

    getline(File, txt);
    txt = cropValue(txt);

    return txt;
}

Type File::getClassNumber(string className) {

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
    return ERROR;
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

    Truck *truck = new Truck(vehicleData[0], status, vehicleData[1], vehicleData[2], 3,
                             3, vehicleData[5] == "1", repairs, roadRegister);

    return truck;
}

Status *File::readStatus() {
    getline(File, nextLine);

    string statusType = getValue();

    switch (getStatusNumber(statusType)) {
        case AVAILABLE:
            return new Available(AVAILABLE);
        case ROAD:
            getline(File, nextLine);
            return readRoad(getValue());
        case BROKE:
            return readBroke();
        case REPAIR:
            getline(File, nextLine);
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

    return new Road(ROAD, distance, driver, start, end);
}

Broke *File::readBroke() {
    string name = getValue();
    string description = getValue();
    return new Broke(BROKE, name, description);
}

Driver *File::readShortDriver() {
    string name = cropValue(nextLine);
    string surname = getValue();
    return new Driver(name, surname);
}

Driver *File::readDriver() {
    string id = cropValue(nextLine);
    vector<string> driverData = getNLines(3);
    bool isAvailable = driverData[2] == "available";
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
    return new Repair(REPAIR, name, description, date);
}

vector<Repair *> File::readRepairs() {
    getline(File, nextLine);
    getline(File, nextLine);

    vector<Repair *> repairs;
    while (nextLine.substr(4, 7) == "- name:") {
        repairs.push_back(readRepair());
        getline(File, nextLine);
    }

    return repairs;
}

vector<Road *> File::readRegister() {
    getline(File, nextLine);

    vector<Road *> roadRegister;
    while (nextLine.length() &&  nextLine.substr(4, 7) == "- name:") {
        roadRegister.push_back(readRoad());
        getline(File, nextLine);
    }
    return roadRegister;
}

void File::readDriversData(const string &fileName, Fleet *&fleet) {
    File.open(fileName, ios::in);

    if (!File.is_open()) {
        cout << "Nie znaleziono pliku " << fileName << endl;
        return;
    }

    bool validData = true;
    getline(File, nextLine);
    Driver *driver;

    while (!File.eof() && validData) {
        if (nextLine.substr(0, 5) == "- id:") {
            driver = readDriver();
            fleet->addDriver(driver);
            getline(File, nextLine);
        } else {
            validData = false;
        }
    }
//    fleet->log();
    File.close();
}

string File::saveData(Fleet *fleet, string fileName) {
    if (fileName == "") {
        fileName = "new.yaml";
    }

    return fileName;
}
