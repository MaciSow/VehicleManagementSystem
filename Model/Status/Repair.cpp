#include "Repair.h"

Repair::Repair(StatusType statusType, const string &name, const string &desrciption, const Date &fixDate) : Status(
        statusType), name(name), desrciption(desrciption), fixDate(fixDate) {}

Repair::~Repair() {

}