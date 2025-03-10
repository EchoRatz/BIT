#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkpalin(const char *str, int left, int right)
{
    while (left < right && isspace(str[left]))
    {
        left++;
    }
    while (right > left && isspace(str[right]))
    {
        right--;
    }

    if (left >= right)
    {
        return 1;
    }

    if (tolower(str[left]) != tolower(str[right]))
    {
        return 0;
    }

    return checkpalin(str, left + 1, right - 1);
}

int main()
{
    char word[20];

    scanf("%[^\n]", word);

    int length = strlen(word);

    if (checkpalin(word, 0, length - 1))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}