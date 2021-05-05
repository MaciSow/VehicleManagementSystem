#ifndef VEHICLEMENAGMENTSYSTEM_STATUS_H
#define VEHICLEMENAGMENTSYSTEM_STATUS_H

#include <string>
#include <vector>
#include <iostream>
#include "../Others/StatusType.h"

using namespace std;

class Status {
protected:
    StatusType statusType;
public:
    StatusType getStatusType() const;

public:
    Status(StatusType statusType);

    virtual ~Status() = default;

    void log();

    string getStatusName();
};


#endif //VEHICLEMENAGMENTSYSTEM_STATUS_H
