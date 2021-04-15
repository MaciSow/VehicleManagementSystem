#ifndef VEHICLEMENAGMENTSYSTEM_BUS_H
#define VEHICLEMENAGMENTSYSTEM_BUS_H

#include "PeopleTransport.h"

class Bus : public virtual PeopleTransport{
public:
    Bus(const string &plate1, const string &status1, const string &brand1, const string &model1,
        const string &plate, const string &status, const string &brand, const string &model, int seatsAmount,
        bool isCoach, bool hasWc);

    virtual ~Bus();

private:
    bool isCoach;
    bool hasWC;
};

#endif //VEHICLEMENAGMENTSYSTEM_BUS_H
