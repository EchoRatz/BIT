#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 1000

int charCompare(const void *a, const void *b)
{
    char charA = *(const char *)a;
    char charB = *(const char *)b;

    if (isdigit(charA) && !isdigit(charB))
        return -1;
    if (!isdigit(charA) && isdigit(charB))
        return 1;
    if (isupper(charA) && islower(charB))
        return -1;
    if (islower(charA) && isupper(charB))
        return 1;

    return charA - charB;
}

void processstring(char *str)
{
    int len = strlen(str);
    qsort(str, len, sizeof(char), charCompare);

    int index = 1;
    for (int i = 1; i < len; i++)
    {
        if (str[i] != str[i - 1])
        {
            str[index++] = str[i];
        }
    }
    str[index] = '\0';
}

int main()
{
    char str1[MAX_LEN], str2[MAX_LEN];
    scanf("%s %s", str1, str2);

    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (!isdigit(str1[i]) && !isupper(str1[i]) && !islower(str1[i]))
        {
            printf("Wrong Input!\n");
            return 1;
        }
    }

    for (int i = 0; str2[i] != '\0'; i++)
    {
        if (!isdigit(str2[i]) && !isupper(str2[i]) && !islower(str2[i]))
        {
            printf("Wrong Input!\n");
            return 1;
        }
    }

    char *mergedString = malloc(strlen(str1) + strlen(str2) + 1);
    if (mergedString == NULL)
    {
        printf("Wrong Input!\n");
        return 1;
    }

    strcpy(mergedString, str1);
    strcat(mergedString, str2);

    processstring(mergedString);

    printf("%s\n", mergedString);

    free(mergedString);
}