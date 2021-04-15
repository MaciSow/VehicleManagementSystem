#include "Truck.h"


Truck::Truck(const string &plate1, const string &status1, const string &brand1, const string &model1,
             const string &plate, const string &status, const string &brand, const string &model, int capacity,
             int axisAmount, bool hasTrailer) : Vehicle(plate1, status1, brand1, model1),
                                                WareTransport(plate, status, brand, model, capacity),
                                                axisAmount(axisAmount), hasTrailer(hasTrailer) {}

Truck::~Truck() {

}