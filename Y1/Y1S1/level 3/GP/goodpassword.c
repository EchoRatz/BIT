#include <stdio.h>
#include <ctype.h>

int GoodPassword(const char *password)
{
    int length = 0, Uppercase = 0, Lowercase = 0, Digit = 0;

    while (password[length] != '\0')
    {

        if (isupper(password[length]))
        {
            Uppercase = 1;
        }

        else if (islower(password[length]))
        {
            Lowercase = 1;
        }

        else if (isdigit(password[length]))
        {
            Digit = 1;
        }

        length++;
    }

    return (length >= 8) && Uppercase && Lowercase && Digit;
}

int main()
{

    char password[50];

    scanf("%[^\n]", &password);

    if (GoodPassword(password))
    {
        printf("Good password!\n");
    }
    else
    {
        printf("Bad password!\n");
    }
}