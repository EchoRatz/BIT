#include <stdio.h>
#include <string.h>
#include <ctype.h>

void delete(char *str)
{
    int i, j;

    for (i = 0, j = 0; str[i] != '\0'; i++)
    {
        if (tolower(str[i]) != 'a' && tolower(str[i]) != 'e' && tolower(str[i]) != 'i' && tolower(str[i]) != 'o' && tolower(str[i]) != 'u')
        {
            str[j++] = str[i];
        }
    }

    str[j] = '\0';
}

int main()
{

    int i, times;
    scanf("%d", &times);

    while (getchar() != '\n')
        ;
    for (i = 0; i < times; i++)
    {

        char string[50];
        fgets(string, sizeof(string), stdin);

        if (string[strlen(string) - 1] == '\n')
        {
            string[strlen(string) - 1] == '\0';
        }

        delete (string);

        printf("%s", string);
    }
}