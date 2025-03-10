#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[100];
    char numberStr[100];
    double number;

    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = 0;

    numberStr[0] = '\0';

    char *token = strtok(input, " ");
    while (token != NULL)
    {
        strcat(numberStr, token);
        token = strtok(NULL, " ");
    }

    // printf("PNS : %s\n", numberStr);

    number = strtod(numberStr, NULL);

    printf("%.8f\n", number);
    return 0;
}