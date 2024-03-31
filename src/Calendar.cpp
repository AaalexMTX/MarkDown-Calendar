#include "../include/Calendar.h"
using namespace std;

void Calendar::printCalendar(int d) const
{
    int allDay = targetDate.dayOfMonth();         // 该月份总日期
    int week = targetDate.weekOfTheFirstDay(1);   // 起始星期
    int rowNum = ceil((week - 1 + allDay) / 7.0); // 计算行数28天可能就4行

    cout << "总日期 起始星期 行数" << endl;
    cout << allDay << "     " << week << "      " << rowNum << endl;
    // printf("%d.%2d  Record + Agency\n", y, m);
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
            if ((i == 0 && j + 1 >= week || i > 0) && d <= allDay)
            {
                printf("%2d<br><br>|", d++);
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
