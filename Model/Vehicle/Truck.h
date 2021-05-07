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

    Truck(const string &plate,
          Status *status,
          const string &brand,
          const string &model,
          int capacity,
          int axisAmount,
          bool hasTrailer);


    virtual ~Truck();

    void log();

    VehicleType getVehicleType();

    vector<string> getVehicleAllData();
};

#endif //VEHICLEMENAGMENTSYSTEM_TRUCK_H
