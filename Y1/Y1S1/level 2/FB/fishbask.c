#include <stdio.h>
#include <stdlib.h>

int dayInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int leapYearCheck(int years)
{
    if (years % 400 == 0)
    {
        return 1;
    }
    if (years % 4 == 0 && years % 100 != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int amountDay(int year, int month, int day)
{
    int result = 0;
    int i;

    for (i = 1; i < year; i++)
    {
        if (leapYearCheck(i))
        {
            result += 366;
        }
        else
        {
            result += 365;
        }
    }
    for (i = 1; i < month; i++)
    {
        result += dayInMonth[i];

        if (leapYearCheck(year) && i == 2)
        {
            result++;
        }
    }
    result += day;
    return result;
}

int main()
{

    int times, i, startYear = 1990, startMonth = 1, startDay = 1, years, months, days, amountofday, remain;

    scanf("%d", &times);

    for (i = 0; i < times; i++)
    {
        scanf("%d ,%d ,%d", &years, &months, &days);

        amountofday = amountDay(years, months, days) - amountDay(startYear, 1, 1);

        remain = amountofday % 5;

        if (remain < 3)
        {
            printf("He was fishing on %d,%d,%d\n", years, months, days);
        }
        else
        {
            printf("He was basking on %d,%d,%d\n", years, months, days);
        }
    }
}