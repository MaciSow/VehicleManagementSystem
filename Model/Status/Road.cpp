#include "Road.h"


Road::~Road() {
}

Road::Road(int distance, Driver *driver, Date *startDate, Date *endDate)
        : Status(ROAD),
          distance(distance),
          driver(driver),
          startDate(startDate),
          endDate(endDate) {}

Road::Road(int distance, Driver *driver, int pause)
        : Status(ROAD),
          distance(distance),
          driver(driver),
          startDate(new Date()) {
    int roadTime = floor(distance / 500);
    endDate = new Date();
    endDate->addDays(roadTime + pause);
}


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

void Road::setEndDate(Date *endDate) {
    Road::endDate = endDate;
}

void Road::setReturn() {
// todo magic function to calculate days
}