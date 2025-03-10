#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, low, high, operate, DigitNum, ArmNum, sum, counter = 0;

    scanf("%d", &DigitNum);

    high = pow(10, DigitNum);
    low = pow(10, DigitNum - 1);

    for (i = low; i < high; i++)
    {
        ArmNum = i;
        sum = 0;

        for (j = DigitNum - 1; ArmNum != 0; j--)
        {
            operate = pow(10, j);
            sum += pow(ArmNum / operate, DigitNum);
            ArmNum %= operate;
        }
        if (sum == i)
        {
            printf("%d\n", i);
            counter++;
        }
    }
    if (counter == 0)
    {
        printf("No output.\n");
    }
}