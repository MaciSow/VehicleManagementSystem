#include "PeopleTransport.h"


PeopleTransport::PeopleTransport(const string &plate, const string &status, const string &brand, const string &model,
                                 int seatsAmount) : Vehicle(plate, status, brand, model), seatsAmount(seatsAmount) {}

PeopleTransport::~PeopleTransport() {

}