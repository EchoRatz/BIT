#include <stdio.h>
int main()
{

    int value;
    scanf("%d", &value);
    value *= 10;

    if (value % 16 == 0)
    {
        printf("%d,%d,%d\n", (value / 16) * 10, (value / 16) * 12, (value / 16) * 9);
    }
    else
    {
        printf("No change.\n");
    }
}