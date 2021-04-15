#ifndef VEHICLEMENAGMENTSYSTEM_BROKE_H
#define VEHICLEMENAGMENTSYSTEM_BROKE_H

#include "Status.h"

class Broke : public Status {
private:
    string name;
    string description;

public:
    Broke(StatusType statusType, const string &name, const string &description);

    virtual ~Broke();

};

#endif //VEHICLEMENAGMENTSYSTEM_BROKE_H
