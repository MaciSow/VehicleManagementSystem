#ifndef VEHICLEMENAGMENTSYSTEM_TRUCK_H
#define VEHICLEMENAGMENTSYSTEM_TRUCK_H


#include "WareTransport.h"

class Truck : public virtual WareTransport {
private:
    int axisAmount;
    bool hasTrailer;
public:
    Truck(const string &plate,
          Status *status,
          const string &brand,
          const string &model,
          int capacity,
          int axisAmount,
          bool hasTrailer,
          vector<Repair *> repairs,
          vector<Road *> roadRegister);

    virtual ~Truck();

    void log();
};

#endif //VEHICLEMENAGMENTSYSTEM_TRUCK_H
