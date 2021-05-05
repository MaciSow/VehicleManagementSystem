#include "Road.h"


Road::~Road() {
}

Road::Road(StatusType statusType, int distance, Driver *driver, Date *startDate, Date *endDate)
        : Status(statusType),
          distance(distance),
          driver(driver),
          startDate(startDate),
          endDate(endDate) {}

void Road::log() {
    cout << distance << endl;
    driver->log();
    startDate->log();
    endDate->log();
}

vector<string> Road::getRoadData() {
    vector<string> roadData;
    roadData.push_back(driver->getFullName());
    roadData.push_back(to_string(distance));
    roadData.push_back(startDate->getStringDate());
    roadData.push_back(endDate->getStringDate());
    return roadData;
}

