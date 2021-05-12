#include "Driver.h"

Driver::Driver(const string &id, const string &name, const string &surname, bool isAvailable)
        : id(id), name(name),
          surname(surname),
          isAvailable(isAvailable) {}

Driver::~Driver() {

}

Driver::Driver(const string &name, const string &surname, bool isAvailable)
        : name(name), surname(surname), isAvailable(isAvailable) {
    generateId();
}

Driver::Driver(const string &name, const string &surname) : id(""), name(name), surname(surname) {}

void Driver::setId(const string &id) {
    Driver::id = id;
}

void Driver::log() {
    if (id.length()) {
        cout << id << endl;
    }

    cout << name << endl << surname << endl;

    if (isAvailable) {
        cout << "available" << endl;
    } else {
        cout << "road" << endl;
    }

    cout << "=========" << endl;
}

bool Driver::isAvailableStatus() const {
    return isAvailable;
}

string Driver::getFullName() {
    return name + " " + surname;
}

const string &Driver::getId() const {
    return id;
}

void Driver::setAvailable(bool isAvailable) {
    this->isAvailable = isAvailable;
}

vector<string> Driver::getAllData() {
    vector<string> data = {name, surname, getStatusName()};
    return data;
}

string Driver::getStatusName() {
    return isAvailable ? "Available" : "On the road";
}

string Driver::getStatusTypeName() {
    return isAvailable ? "Available" : "Road";
}

void Driver::setName(const string &name) {
    Driver::name = name;
}

void Driver::setSurname(const string &surname) {
    Driver::surname = surname;
}

vector<string> Driver::getDriverPrintData() {
    vector<string> driverData;
    driverData.push_back("id: " + id);
    driverData.push_back("name: " + name);
    driverData.push_back("surname: " + surname);
    driverData.push_back("status: " + getStatusTypeName());
    return driverData;
}

void Driver::generateId() {
    srand(time(NULL));
    string id = "";
    int length = name.length() < 3 ? name.length() : 3;
    id += name.substr(0, length);

    id += to_string((rand() % 9000) + 7);

    length = surname.length() < 3 ? surname.length() : 3;
    id += surname.substr(0, length);

    this->id = id;
}
