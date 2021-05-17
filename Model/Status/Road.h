#ifndef VEHICLEMENAGMENTSYSTEM_ROAD_H
#define VEHICLEMENAGMENTSYSTEM_ROAD_H

#include <vector>
#include <math.h>

#include "Status.h"
#include "../Driver.h"
#include "../Others/Date.h"

class Road : public Status{
public:
    Road(int distance, Driver *driver, Date *startDate, Date *endDate);

    Road(int distance, Driver *driver , int pause);

    virtual ~Road();

    vector<string> getRoadData();

    void setEndDate(Date *endDate);

    void setReturn();

    vector<string> getStatusPrintData(bool shortVersion = false);

private:
    int distance;
    Driver * driver;
    Date *startDate;
    Date * endDate;
};


#endif //VEHICLEMENAGMENTSYSTEM_ROAD_H
