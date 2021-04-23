#ifndef VEHICLEMENAGMENTSYSTEM_AVAILABLE_H
#define VEHICLEMENAGMENTSYSTEM_AVAILABLE_H

#include "Status.h"

class Available: public Status {
public:
    Available(StatusType statusType);

    virtual ~Available();
};


#endif //VEHICLEMENAGMENTSYSTEM_AVAILABLE_H
