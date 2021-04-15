#ifndef VEHICLEMENAGMENTSYSTEM_REPAIR_H
#define VEHICLEMENAGMENTSYSTEM_REPAIR_H

#include "Status.h"
#include "../Others/Date.h"

class Repair : public Status{
public:
    Repair(StatusType statusType, const string &name, const string &desrciption, const Date &fixDate);

    virtual ~Repair();

private:
    string name;
    string desrciption;
    Date fixDate;
};

#endif //VEHICLEMENAGMENTSYSTEM_REPAIR_H
