#include "WareTransport.h"

WareTransport::WareTransport(const string &plate, Status *status, const string &brand, const string &model,
                             int capacity) : Vehicle(plate, status, brand, model), capacity(capacity) {}

WareTransport::WareTransport() {}

WareTransport::~WareTransport() {

}
