#include "PeopleTransport.h"


PeopleTransport::PeopleTransport(const string &plate, Status *status, const string &brand, const string &model,
                                 int seatsAmount) : Vehicle(plate, status, brand, model), seatsAmount(seatsAmount) {}

PeopleTransport::~PeopleTransport() {

}

PeopleTransport::PeopleTransport() {

}
