#ifndef VEHICLEMENAGMENTSYSTEM_VAN_H
#define VEHICLEMENAGMENTSYSTEM_VAN_H


#include "WareTransport.h"

class Van : public virtual WareTransport {
public:
    Van(const string &plate1, const string &status1, const string &brand1, const string &model1,
        const string &plate, const string &status, const string &brand, const string &model, int capacity,
        bool isDoubleWheel, bool isSlideDoors);

    virtual ~Van();

private:
    bool isDoubleWheel;
    bool isSlideDoors;
};

#endif //VEHICLEMENAGMENTSYSTEM_VAN_H
