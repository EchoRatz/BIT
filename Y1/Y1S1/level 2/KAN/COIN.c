#include <stdio.h>

int GCD(num1, num2)
{
    int result, i;
    for (i = num1; i > 0; i--)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            result = i;
            break;
        }
    }
    return result;
}

int LCM(num1, num2)
{
    int result, i;
    for (i = num2; 1; i++)
    {
        if (i % num1 == 0 && i % num2 == 0)
        {
            result = i;
            break;
        }
    }
    return result;
}

int main()
{
    int upperNum, lowerNum, upperNum2, lowerNum2, lowerLCM, numMultiply, numMultiply2, ans[2];
    char operator;

    scanf("%d/%d %c %d/%d", &upperNum, &lowerNum, &operator, & upperNum2, &lowerNum2);

    if (operator== 43)
    {
        if (lowerNum == lowerNum2)
        {
            ans[0] = upperNum + upperNum2;
            ans[1] = lowerNum;

            if (ans[0] % ans[1] == 0)
                printf("%d/%d %c %d/%d = %d", upperNum, lowerNum, operator, upperNum2, lowerNum2, ans[0] / ans[1]);
            else
                printf("%d/%d %c %d/%d = %d/%d", upperNum, lowerNum, operator, upperNum2, lowerNum2, ans[0], ans[1]);
        }
        else
        {
            lowerLCM = LCM(lowerNum, lowerNum2);

            numMultiply = lowerLCM / lowerNum;
            numMultiply2 = lowerLCM / lowerNum2;

            upperNum *= numMultiply;
            upperNum2 *= numMultiply2;

            ans[0] = upperNum + upperNum2;
            ans[1] = lowerLCM;

            if (ans[0] % ans[1] == 0)
                printf("%d/%d %c %d/%d = %d", upperNum, lowerNum, operator, upperNum2, lowerNum2, ans[0] / ans[1]);
            else
                printf("%d/%d %c %d/%d = %d/%d", upperNum, lowerNum, operator, upperNum2, lowerNum2, ans[0], ans[1]);
        }
    }
    else if (operator== 45)
    {
    }
    else if (operator== 42)
    {
    }
    else if (operator== 47)
    {
    }
}
