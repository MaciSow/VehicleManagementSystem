#include "Repair.h"

Repair::Repair(const string &name, const string &description, Date *fixDate)
        : Status(REPAIR),
          name(name),
          description(description),
          fixDate(fixDate) {}

Repair::~Repair() {

}

void Repair::log() {
    cout << name << endl << description << endl;
    fixDate->log();
}

vector<string> Repair::getRepairData() {
    vector<string> repairData;
    repairData.push_back(name);
    repairData.push_back(description);
    repairData.push_back(fixDate->getStringDate());

    return repairData;
}
