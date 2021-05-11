#include "Driver.h"

Driver::Driver(const string &id, const string &name, const string &surname, bool isAvailable)
        : id(id), name(name),
          surname(surname),
          isAvailable(isAvailable) {}

Driver::~Driver() {

}

Driver::Driver(const string &name, const string &surname, bool isAvailable)
        : name(name), surname(surname), isAvailable(isAvailable) {
    id = 14;
    // todo driverId generator
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

void Driver::setName(const string &name) {
    Driver::name = name;
}

void Driver::setSurname(const string &surname) {
    Driver::surname = surname;
}
