#ifndef DATE_H
#define DATE_H

class Date
{
public:
    Date() = default;
    Date(int y, int m) : year(y), month(m){};

    int dayOfMonth() const;
    int weekOfTheFirstDay(int day = 1) const; // 默认参数 声明和定义留一处即可，默认前者
    int isLeap() const;
    int getYear() const;
    int getMonth() const;

private:
    int year;
    int month;
};

#endif
