#include "Repair.h"

Repair::Repair(StatusType statusType, const string &name, const string &description, Date *fixDate) : Status(
        statusType), name(name), description(description), fixDate(fixDate) {}

Repair::~Repair() {

}

void Repair::log() {
    cout << name << endl << description << endl;
    fixDate->log();
}
