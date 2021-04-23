#ifndef VEHICLEMENAGMENTSYSTEM_PEOPLETRANSPORT_H
#define VEHICLEMENAGMENTSYSTEM_PEOPLETRANSPORT_H

#include "Vehicle.h"

class PeopleTransport : public virtual Vehicle {
protected:
    int seatsAmount;

public:
    PeopleTransport(const string &plate, Status *status, const string &brand, const string &model,
                    int seatsAmount);

    PeopleTransport();

    virtual ~PeopleTransport();
};

#endif //VEHICLEMENAGMENTSYSTEM_PEOPLETRANSPORT_H
