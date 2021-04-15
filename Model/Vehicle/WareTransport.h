#ifndef VEHICLEMENAGMENTSYSTEM_WARETRANSPORT_H
#define VEHICLEMENAGMENTSYSTEM_WARETRANSPORT_H


#include "Vehicle.h"

class WareTransport : public virtual Vehicle {
protected:
    int capacity;
public:
    WareTransport(const string &plate, const string &status, const string &brand, const string &model, int capacity);

    virtual ~WareTransport();
};


#endif //VEHICLEMENAGMENTSYSTEM_WARETRANSPORT_H
