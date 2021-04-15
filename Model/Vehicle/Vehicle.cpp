#include "Vehicle.h"

Vehicle::Vehicle(const string &plate, const string &status, const string &brand, const string &model) : plate(plate),
                                                                                                        status(status),
                                                                                                        brand(brand),model(model) {}
Vehicle::~Vehicle() {
}