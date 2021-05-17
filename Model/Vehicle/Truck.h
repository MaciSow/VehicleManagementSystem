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

    VehicleType getVehicleType();

    vector<string> getVehicleAllData();

    void updateAllData(vector<string> vehicleData) override;

    vector<string> getSpecificPrintData();
};

#endif //VEHICLEMENAGMENTSYSTEM_TRUCK_H
