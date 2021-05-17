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
    int roadTime = ceil(distance / 500);
    endDate = new Date();
    endDate->addDays(roadTime + pause);
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
    this->endDate = endDate;
}

void Road::setReturn() {
    int addDays = ceil(distance / 1000);
    endDate->addDays(addDays);
}

vector<string> Road::getStatusPrintData(bool shortVersion) {
    vector<string> roadData;
    vector<string> driverData = driver->getAllData();

    if (!shortVersion) {
        roadData.push_back("type: " + getStatusTypeName());
        roadData.push_back("id: " + driver->getId());
    }
    roadData.push_back("name: " + driverData[0]);
    roadData.push_back("surname: " + driverData[1]);
    roadData.push_back("distance: " + to_string(distance));
    roadData.push_back("start: " + startDate->getStringDate("-"));
    roadData.push_back("end: " + endDate->getStringDate("-"));

    return roadData;
}