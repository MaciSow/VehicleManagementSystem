#include "Driver.h"

Driver::Driver(const string &id, const string &name, const string &surname, bool isAvailable) : id(id), name(name),
                                                                                                surname(surname),
                                                                                                isAvailable(
                                                                                                        isAvailable) {}

Driver::~Driver() {

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
