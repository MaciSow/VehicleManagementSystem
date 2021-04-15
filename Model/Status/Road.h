#ifndef VEHICLEMENAGMENTSYSTEM_ROAD_H
#define VEHICLEMENAGMENTSYSTEM_ROAD_H

#include "Status.h"
#include "../Driver.h"
#include "../Others/Date.h"

class Road : public Status{
public:
    Road(StatusType statusType, const string &id, const Driver &driver, const Date &startDate, const Date &endDate);

    virtual ~Road();

private:
    string id;
    Driver driver;
    Date startDate;
    Date endDate;
};


#endif //VEHICLEMENAGMENTSYSTEM_ROAD_H
