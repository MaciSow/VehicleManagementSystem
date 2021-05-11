#ifndef VEHICLEMENAGMENTSYSTEM_BROKE_H
#define VEHICLEMENAGMENTSYSTEM_BROKE_H

#include "Status.h"

class Broke : public Status {
private:
    string name;
    string description;

public:
    Broke(const string &name, const string &description);

    virtual ~Broke();

    vector<string> getData();

    vector<string> getStatusPrintData(bool shortVersion = false);
};

#endif //VEHICLEMENAGMENTSYSTEM_BROKE_H
