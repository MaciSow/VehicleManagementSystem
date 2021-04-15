#ifndef VEHICLEMENAGMENTSYSTEM_TRUCK_H
#define VEHICLEMENAGMENTSYSTEM_TRUCK_H


#include "WareTransport.h"

class Truck : public virtual WareTransport {
private:
    int axisAmount;
    bool hasTrailer;
public:
    Truck(const string &plate1, const string &status1, const string &brand1, const string &model1,
          const string &plate, const string &status, const string &brand, const string &model, int capacity,
          int axisAmount, bool hasTrailer);

    virtual ~Truck();

};

#endif //VEHICLEMENAGMENTSYSTEM_TRUCK_H
