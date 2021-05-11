#ifndef VEHICLEMENAGMENTSYSTEM_VAN_H
#define VEHICLEMENAGMENTSYSTEM_VAN_H


#include "WareTransport.h"

class Van : public virtual WareTransport {
private:
    bool hasDoubleWheel;
    bool hasSlideDoors;

public:
    Van(const string &plate,
        Status *status,
        const string &brand,
        const string &model,
        int capacity,
        bool hasDoubleWheel,
        bool hasSlideDoors,
        vector<Repair *> repairs,
        vector<Road *> roadRegister);


    Van(const string &plate,
        Status *status,
        const string &brand,
        const string &model,
        int capacity,
        bool hasDoubleWheel,
        bool hasSlideDoors
    );

    virtual ~Van();

    void log();

    VehicleType getVehicleType();

    vector<string> getVehicleAllData();

    void updateAllData(vector<string> vehicleData) override;

    vector<string> getSpecificPrintData();
};

#endif //VEHICLEMENAGMENTSYSTEM_VAN_H
