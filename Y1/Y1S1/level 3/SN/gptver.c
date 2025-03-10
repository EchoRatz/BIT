#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void remove_decimal(char *str, int *decimal_pos)
{
    char *dot = strchr(str, '.');
    if (dot != NULL)
    {
        *decimal_pos = strlen(str) - (dot - str) - 1;
        memmove(dot, dot + 1, strlen(dot));
    }
    else
    {
        *decimal_pos = 0;
    }
}

void add_zeros(char *str, int exponent)
{
    int len = strlen(str);
    for (int i = 0; i < exponent; i++)
    {
        str[len + i] = '0';
    }
    str[len + exponent] = '\0';
}

void format_output(char *num, int decimal_pos)
{
    int len = strlen(num);
    if (decimal_pos > len)
    {
        // Pad with zeros if decimal position is beyond current length
        for (int i = len; i < decimal_pos; i++)
        {
            num[i] = '0';
        }
        num[decimal_pos] = '.';
        num[decimal_pos + 9] = '\0'; // 8 digits after the decimal point plus null terminator
    }
    else
    {
        // Insert decimal point in the correct position
        memmove(num + decimal_pos + 1, num + decimal_pos, len - decimal_pos + 1);
        num[decimal_pos] = '.';
        num[decimal_pos + 9] = '\0'; // 8 digits after the decimal point plus null terminator
    }
}

int main()
{
    char number[200];
    int exponent, decimal_pos;

    printf("Enter a number in scientific notation (e.g., 2.3e10): ");
    scanf("%s e %d", number, &exponent);

    remove_decimal(number, &decimal_pos);
    add_zeros(number, exponent);
    format_output(number, decimal_pos + exponent);

    printf("Result: %s\n", number);
    return 0;
}