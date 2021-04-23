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

