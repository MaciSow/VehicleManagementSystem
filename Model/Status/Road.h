#ifndef VEHICLEMENAGMENTSYSTEM_ROAD_H
#define VEHICLEMENAGMENTSYSTEM_ROAD_H

#include "Status.h"
#include "../Driver.h"
#include "../Others/Date.h"

class Road : public Status{
public:
    Road(StatusType statusType, int distance, Driver *driver, Date *startDate, Date *endDate);

    virtual ~Road();

    void log();

private:
    int distance;
    Driver * driver;
    Date *startDate;
    Date * endDate;
};


#endif //VEHICLEMENAGMENTSYSTEM_ROAD_H
