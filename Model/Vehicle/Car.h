#ifndef VEHICLEMENAGMENTSYSTEM_CAR_H
#define VEHICLEMENAGMENTSYSTEM_CAR_H


#include "PeopleTransport.h"

class Car : public virtual PeopleTransport {
public:
    Car(const string &plate1, const string &status1, const string &brand1, const string &model1,
        const string &plate, const string &status, const string &brand, const string &model, int seatsAmount,
        int doorsAmount, const string &bodyStyle);

    virtual ~Car();

private:
    int doorsAmount;
    string bodyStyle;
};


#endif //VEHICLEMENAGMENTSYSTEM_CAR_H
