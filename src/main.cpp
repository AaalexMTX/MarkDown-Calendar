#include <iostream>
#include "../include/Calendar.h"
using namespace std;

/*
zeller(蔡勒)公式 快速算日期对应星期  从1582开始
expression: w=y+[y/4]+[c/4]-2c+[26(m+1)/10]+d-1
explain: w星期；c世纪-1；y年（后两位数）m月（m大于等于3，小于等于14，即在蔡勒公式中，某年的1、2月要看作上一年的13、14月来计算
eg: 比如2003年1月1日要看作2002年的13月1日来计算
ans: 0星期天 5星期五
*/

int main()
{
    int year, month;
    cout << "input year month (eg: 2024 2) -- > ";
    cin >> year >> month;

    Calendar targetCalendar(year, month);
    targetCalendar.printCalendar();
    return 0;
}