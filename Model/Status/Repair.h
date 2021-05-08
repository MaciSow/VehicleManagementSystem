#ifndef VEHICLEMENAGMENTSYSTEM_REPAIR_H
#define VEHICLEMENAGMENTSYSTEM_REPAIR_H

#include "Status.h"
#include "../Others/Date.h"

class Repair : public Status {
public:
    Repair(const string &name, const string &description, Date *fixDate);

    virtual ~Repair();

    void log();

    vector<string> getRepairData();

private:
    string name;
    string description;
    Date *fixDate;
};

#endif //VEHICLEMENAGMENTSYSTEM_REPAIR_H
