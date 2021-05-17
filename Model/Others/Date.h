#ifndef VEHICLEMENAGMENTSYSTEM_DATE_H
#define VEHICLEMENAGMENTSYSTEM_DATE_H

#include <string>
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int day, int month, int year);

    Date(string date);

    Date();

    virtual ~Date();

    string getStringDate(string separator = ".");

    void addDays(int days);

    int getDay() const;

    void setCurrentDate();
};


#endif //VEHICLEMENAGMENTSYSTEM_DATE_H
