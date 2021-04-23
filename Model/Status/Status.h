#ifndef VEHICLEMENAGMENTSYSTEM_STATUS_H
#define VEHICLEMENAGMENTSYSTEM_STATUS_H

#include <string>
#include <iostream>

using namespace std;

enum StatusType {
    AVAILABLE, ROAD, BROKE, REPAIR, STATUSERROR
};

class Status {
protected:
    StatusType statusType;
public:
    Status(StatusType statusType);

    virtual ~Status() = default;

    void log();
};


#endif //VEHICLEMENAGMENTSYSTEM_STATUS_H
