#ifndef VEHICLEMENAGMENTSYSTEM_CAR_H
#define VEHICLEMENAGMENTSYSTEM_CAR_H

#include "iostream"
#include "PeopleTransport.h"

class Car : public virtual PeopleTransport {
private:
    int doorsAmount;
    string bodyStyle;

public:
    Car(const string &plate,
        Status *status,
        const string &brand,
        const string &model,
        int seatsAmount,
        int doorsAmount,
        const string &bodyStyle,
        vector<Repair*>repairs,
        vector<Road* > roadRegister);

    virtual ~Car();

    void log();



};


#endif //VEHICLEMENAGMENTSYSTEM_CAR_H
