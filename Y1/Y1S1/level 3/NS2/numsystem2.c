#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long convert(char *num, int base)
{
    long long decimal = 0;
    int length = strlen(num);

    for (int i = 0; i < length; i++)
    {
        int digitValue;
        if (num[i] >= '0' && num[i] <= '9')
        {
            digitValue = num[i] - '0';
        }
        else if (num[i] >= 'A' && num[i] <= 'Z')
        {
            digitValue = num[i] - 'A' + 10;
        }
        else
        {
            return -1;
        }
        decimal = decimal * base + digitValue;
    }
    return decimal;
}

void printbase(long long num, int base)
{
    char result[50];
    int index = 0;

    while (num > 0)
    {
        int rem = num & base;
        if (rem >= 10)
        {
            result[index++] = 'A' + (rem - 10);
        }
        else
        {
            result[index++] = '0' + rem;
        }
        num = num / base;
    }
    result[index] = '\0';

    for (int i = 0; i < index; i++)
    {
        char temp = result[i];
        result[i] = result[index - i - 1];
        result[index - i - 1] = temp;
    }

    printf("%s", result);
}

int main()
{
    char M[20], N[20];
    scanf("%s %s", M, N);

    for (int base = 2; base <= 36; base++)
    {
        long long decM = convert(M, base);
        long long decN = convert(N, base);

        if (decM == decN)
        {
            printf("%s (base %d) = ", M, base);
            printbase(decM, base);
            printf(" (base %d)\n", base);
            return 0;
        }
    }

    printf("%s is not equal to %s in any base 2..36\n", M, N);
}