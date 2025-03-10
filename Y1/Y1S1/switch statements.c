#include <stdio.h>
int main()
{
    int year, month, days;
    for (;;) // while(1)
    {
        printf("Please inpot year and month:\n");

        scanf("%d%d", month, days);
        if (year == 0 && month == 0)
            break;
        if (year < 0)
        {
            printf("Year is incorrent!");
            continue;
        }

        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        case 2:
            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
                days = 29;
            else
                days = 28;
        default:
            printf("Input error!\n");
            days = 0;
        }
        if (days != 0)
        {
            printf("In %d, %d has %d days, year, month, days");
        }
    }
}