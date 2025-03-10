#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void add(char *num1, char *num2, char *result)
{
    int len1 = strlen(num1), len2 = strlen(num2);
    int maxlength, carry = 0, sum, i;

    if (len1 > len2)
    {
        maxlength = len1;
    }
    else
    {
        maxlength = len2;
    }

    reverse(num1);
    reverse(num2);

    memset(result, 0, 502);

    for (i = 0; i < maxlength; i++)
    {
        int digit1, digit2;

        if (i < len1)
        {
            digit1 = num1[i] - '0';
        }
        else
        {
            digit1 = 0;
        }

        if (i < len2)
        {
            digit2 = num2[i] - '0';
        }
        else
        {
            digit2 = 0;
        }

        sum = digit1 + digit2 + carry;
        result[i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    if (carry > 0)
    {
        result[i++] = carry + '0';
    }
    result[i] = '\0';

    reverse(result);
    reverse(num1);
    reverse(num2);
}

void subtract(char *num1, char *num2, char *result)
{
    int len1 = strlen(num1), len2 = strlen(num2);
    int i, difference, borrow = 0, isNegative = 0;

    if (len1 < len2 || (len1 == len2 && strcmp(num1, num2) < 0))
    {
        char *temp = num1;
        num1 = num2;
        num2 = temp;
        int tempLen = len1;
        len1 = len2;
        len2 = tempLen;
        isNegative = 1;
    }

    reverse(num1);
    reverse(num2);

    memset(result, 0, 502);

    for (i = 0; i < len1; i++)
    {
        int digit1 = num1[i] - '0';
        int digit2;

        if (i < len2)
        {
            digit2 = num2[i] - '0';
        }
        else
        {
            digit2 = 0;
        }

        digit1 -= borrow;

        if (digit1 < digit2)
        {
            digit1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        difference = digit1 - digit2;
        result[i] = difference + '0';
    }

    int resultLen = len1;
    while (resultLen > 1 && result[resultLen - 1] == '0')
    {
        resultLen--;
    }
    result[resultLen] = '\0';

    reverse(result);
    reverse(num1);
    reverse(num2);

    if (isNegative)
    {
        memmove(result + 1, result, resultLen + 1);
        result[0] = '-';
    }
}

int main()
{
    int times;
    scanf("%d", &times);
    getchar();

    while (times--)
    {
        char inputline[1003], num1[501], num2[501], operator;
        char *token;
        fgets(inputline, sizeof(inputline), stdin);

        size_t len = strlen(inputline);
        if (len > 0 && inputline[len - 1] == '\n')
        {
            inputline[len - 1] = '\0';
        }

        int operatorPosition = 0;
        for (int i = 0; inputline[i] != '\0'; i++)
        {
            if (inputline[i] == '+' || inputline[i] == '-')
            {
                operator= inputline[i];
                operatorPosition = i;
                break;
            }
        }

        strncpy(num1, inputline, operatorPosition);
        num1[operatorPosition] = '\0';
        strcpy(num2, inputline + operatorPosition + 1);

        // printf("No.1: %s\nOperator: %c\nNo.2: %s\n", num1, operator, num2);

        char result[502];
        if (operator== '+')
        {
            add(num1, num2, result);
        }
        else
        {
            subtract(num1, num2, result);
        }
        printf("%s\n", result);
    }
}