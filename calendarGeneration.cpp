#include <iostream>
using namespace std;
/*
zeller(蔡勒)公式 快速算日期对应星期  从1582开始
expression: w=y+[y/4]+[c/4]-2c+[26(m+1)/10]+d-1
explain: w星期；c世纪-1；y年（后两位数）m月（m大于等于3，小于等于14，即在蔡勒公式中，某年的1、2月要看作上一年的13、14月来计算
eg: 比如2003年1月1日要看作2002年的13月1日来计算
ans: 0星期天 5星期五
*/

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(const int &year)
{
    return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}

int dayOfMonth(const int &year, const int &month)
{
    if (month == 2)
    {
        return days[month] + is_leap(year);
    }
    return days[month];
}

int weekOfTheFirstDay(int year, int month, int day = 1)
{
    int c = 0;
    if (month <= 2)
    {
        year -= 1;
        month += 12;
    }
    c = year / 100;
    year %= 100;
    return (year + year / 4 + c / 4 - 2 * c + 26 * (month + 1) / 10 + day - 1) % 7;
}

void printCalendar(const int &year, const int &month, int day = 1)
{
    int allDay = dayOfMonth(year, month);         // 该月份总日期
    int week = weekOfTheFirstDay(year, month, 1); // 起始星期
    int rowNum = ceil((week - 1 + allDay) / 7.0); // 计算行数28天可能就4行
    cout << "总日期"
         << " 起始星期"
         << " 行数" << endl;
    cout << allDay << "     " << week << "      " << rowNum << endl;
    printf("%d年%2d月 记事 + 代办\n", year, month);
    printf("| 一 | 二 | 三 | 四 | 五 | 六 | 日 |\n");
    for (int i = 0; i < 7; ++i)
    {
        if (i == 6)
            printf("|:--:|\n");
        else
            printf("|:--:");
    }
    for (int i = 0; i < rowNum; i++)
    {
        printf("|");
        for (int j = 0; j < 7; j++)
        {
            if ((i == 0 && j + 1 >= week || i > 0) && day <= allDay)
            {
                printf("%2d<br><br>|", day++);
            }
            else
            {
                printf("    |");
            }
        }
        if (i != 6)
            printf("\n");
    }
    for (int i = 0; i < 7; ++i)
    {
        printf("| ");
        for (int j = 0; j < 18; j++)
            printf("-");
        if (i == 6)
            printf(" |\n");
    }
}

int mian()
{
    int year, month, day, week;
    cout << "input (year month)--> ";
    cin >> year >> month;
    printCalendar(year, month);
    return 0;
}