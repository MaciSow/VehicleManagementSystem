#ifndef VEHICLEMENAGMENTSYSTEM_BUS_H
#define VEHICLEMENAGMENTSYSTEM_BUS_H

#include "PeopleTransport.h"

class Bus : public virtual PeopleTransport {
private:
    bool isCoach;
    bool hasWC;
public:
    Bus(const string &plate,
        Status *status,
        const string &brand,
        const string &model,
        int seatsAmount,
        bool isCoach,
        bool hasWC,
        vector<Repair *> repairs,
        vector<Road *> roadRegister);

    Bus(const string &plate,
        Status *status,
        const string &brand,
        const string &model,
        int seatsAmount,
        bool isCoach,
        bool hasWC);

    virtual ~Bus();

    VehicleType getVehicleType();

    vector<string> getVehicleAllData();

    void updateAllData(vector<string> vehicleData) override;

    vector<string> getSpecificPrintData();
};

#endif //VEHICLEMENAGMENTSYSTEM_BUS_H
