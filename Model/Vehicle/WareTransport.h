#ifndef VEHICLEMENAGMENTSYSTEM_WARETRANSPORT_H
#define VEHICLEMENAGMENTSYSTEM_WARETRANSPORT_H

#include "Vehicle.h"

class WareTransport : public virtual Vehicle {
protected:
    int capacity;
public:
    WareTransport(const string &plate, Status *status, const string &brand, const string &model, int capacity);

    WareTransport();

    virtual ~WareTransport();
};


#endif //VEHICLEMENAGMENTSYSTEM_WARETRANSPORT_H
