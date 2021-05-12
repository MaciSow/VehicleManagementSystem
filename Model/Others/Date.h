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

    Date getDateFromString(string date);

    void setDateFromString(string date);

    string getStringDate(string separator = ".");

    void log();

    void addDays(int days);

    int getDay() const;

    void setCurrentDate();

    bool checkDateOrder(string youngDate, string oldDate);
};


#endif //VEHICLEMENAGMENTSYSTEM_DATE_H
