#include "Date.h"

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

Date::Date() {
    day = 1;
    month = 1;
    year = 2021;
}

Date::~Date() {

}

Date Date::getDateFromString(string date) {
    int day, month, year;
    day = stoi(date.substr(0, 2));
    month = stoi(date.substr(3, 2));
    year = stoi(date.substr(6, 4));

    return Date(day, month, year);
}

void Date::setDateFromString(string date) {
    day = stoi(date.substr(0, 2));
    month = stoi(date.substr(3, 2));
    year = stoi(date.substr(6, 4));
}

Date::Date(string date) {
    day = stoi(date.substr(0, 2));
    month = stoi(date.substr(3, 2));
    year = stoi(date.substr(6, 4));
}

void Date::log() {
    cout << day << '.' << month << '.' << year << endl;
}

string Date::getStringDate() {
    return to_string(day) + '.' + to_string(month) + '.' + to_string(year);
}

void Date::addDays(int days) {
    day += days;
}
