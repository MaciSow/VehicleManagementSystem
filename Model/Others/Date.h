#ifndef VEHICLEMENAGMENTSYSTEM_DATE_H
#define VEHICLEMENAGMENTSYSTEM_DATE_H

#include <string>
#include <iostream>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date();

    Date(int day, int month, int year);

    Date(string date);

    virtual ~Date();

    Date getDateFromString(string date);

    void setDateFromString(string date);

    string getStringDate(string separator = ".");

    void log();

    void addDays(int days);

    int getDay() const;


};


#endif //VEHICLEMENAGMENTSYSTEM_DATE_H
