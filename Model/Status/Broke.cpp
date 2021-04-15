#include "Broke.h"

Broke::Broke(StatusType statusType, const string &name, const string &description) : Status(statusType), name(name),
                                                                                     description(description) {}

Broke::~Broke() {

}