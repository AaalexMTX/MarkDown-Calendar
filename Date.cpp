#include "Date.h"

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int Date::getYear() const { return this->year; }

int Date::getMonth() const { return this->month; }

int Date::isLeap() const
{
    return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}

int Date::dayOfMonth() const
{
    if (month == 2)
    {
        return days[month] + isLeap();
    }
    return days[month];
}

int Date::weekOfTheFirstDay(int day) const
{
    int c = 0;
    int y = year;
    int m = month;
    if (month <= 2)
    {
        y -= 1;
        m += 12;
    }
    c = year / 100;
    y %= 100;
    return (y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + day - 1) % 7;
}