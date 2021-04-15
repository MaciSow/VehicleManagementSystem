#ifndef VEHICLEMENAGMENTSYSTEM_DATE_H
#define VEHICLEMENAGMENTSYSTEM_DATE_H

using namespace std;

class Date {
public:
    Date(int day, int month, int year);

    virtual ~Date();

private:
    int day;
    int month;
    int year;
};


#endif //VEHICLEMENAGMENTSYSTEM_DATE_H
