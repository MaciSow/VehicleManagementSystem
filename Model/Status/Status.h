#ifndef VEHICLEMENAGMENTSYSTEM_STATUS_H
#define VEHICLEMENAGMENTSYSTEM_STATUS_H

#include <string>
#include <vector>
#include <iostream>
#include "../Others/StatusType.h"
#include "../Others/Date.h"

using namespace std;

class Status {
protected:
    StatusType statusType;
public:
    StatusType getStatusType() const;

    Status(StatusType statusType);

    virtual ~Status() = default;

    virtual vector<string> getData();

    void log();

    string getStatusName();

    string getStatusTypeName();

    virtual vector<string> getStatusPrintData(bool shortVersion = false);
};


#endif //VEHICLEMENAGMENTSYSTEM_STATUS_H
