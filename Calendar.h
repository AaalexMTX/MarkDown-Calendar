#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include <cmath>
#include "Date.h"

class Calendar
{
public:
    Calendar() = default;
    Calendar(int y, int m) : targetDate(y, m){};
    void printCalendar(int d = 1) const;

private:
    Date targetDate;
};

#endif
