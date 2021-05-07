#ifndef VEHICLEMENAGMENTSYSTEM_VAN_H
#define VEHICLEMENAGMENTSYSTEM_VAN_H


#include "WareTransport.h"

class Van : public virtual WareTransport {
private:
    bool isDoubleWheel;
    bool isSlideDoors;

public:
    Van(const string &plate,
        Status *status,
        const string &brand,
        const string &model,
        int capacity,
        bool isDoubleWheel,
        bool isSlideDoors,
        vector<Repair *> repairs,
        vector<Road *> roadRegister);


    Van(const string &plate,
        Status *status,
        const string &brand,
        const string &model,
        int capacity,
        bool isDoubleWheel,
        bool isSlideDoors
    );

    virtual ~Van();

    void log();

    VehicleType getVehicleType();

    vector<string> getVehicleAllData();

    void updateAllData(vector<string> vehicleData) override;
};

#endif //VEHICLEMENAGMENTSYSTEM_VAN_H
