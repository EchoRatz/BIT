#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void multiplypowTen(char *mantissa, int exponent, char *result)
{
    int len = strlen(mantissa);
    int decimalPos = 0;
    for (int i = 0; i < len; ++i)
    {
        if (mantissa[i] == '.')
        {
            decimalPos = len - i - 1;
            break;
        }
    }

    int newLen = len + exponent - decimalPos;
    if (newLen <= 0)
    {
        strcpy(result, "0");
        return;
    }

    int j = 0;
    for (int i = 0; i < newLen; ++i)
    {
        if (i < len && mantissa[i] != '.')
        {
            result[j++] = mantissa[i];
        }
        else
        {
            result[j++] = '0';
        }
    }
    result[j] = '\0';
}

int main()
{

    char input[100];
    char mantissa[50], exponentStr[10], result[200];
    int exponent, i = 0, j = 0;

    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = 0;

    while (input[i] != 'e' && input[i] != 'E' && input[i] != '\0')
    {
        if (input[i] != ' ')
        {
            mantissa[j++] = input[i];
        }
        i++;
    }
    mantissa[j] = '\0';

    while (input[i] == 'e' || input[i] == 'E' || input[i] == ' ')
    {
        i++;
    }

    j = 0;
    while (input[i] != '\0')
    {
        exponentStr[j++] = input[i++];
    }
    exponentStr[j] = '\0';

    exponent = atoi(exponentStr);
    multiplypowTen(mantissa, exponent, result);

    printf("%s\n", result);
}