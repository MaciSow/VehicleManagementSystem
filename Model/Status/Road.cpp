#include "Road.h"

Road::Road(StatusType statusType, const string &id, const Driver &driver, const Date &startDate, const Date &endDate)
        : Status(statusType), id(id), driver(driver), startDate(startDate), endDate(endDate) {}

Road::~Road() {
}