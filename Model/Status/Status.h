#ifndef VEHICLEMENAGMENTSYSTEM_STATUS_H
#define VEHICLEMENAGMENTSYSTEM_STATUS_H

#include <string>

using namespace std;

enum StatusType {
    available, road, broke, repair
};

class Status {
protected:
    StatusType statusType;
public:
    Status(StatusType statusType);

    virtual ~Status() = default;
};


#endif //VEHICLEMENAGMENTSYSTEM_STATUS_H
