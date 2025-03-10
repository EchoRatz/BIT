#include <stdio.h>
#include <string.h>
#include <ctype.h>

void cipher(int mode, int key, char *msg)
{
    int length = strlen(msg);
    key = key % 26;
    // msg = message
    int i;
    for (i = 0; i < length; i++)
    {
        if (isalpha(msg[i]))
        {
            char base = islower(msg[i]) ? 'a' : 'A';

            if (mode == 1)
            {
                msg[i] = (msg[i] - base + key) % 26 + base;
            }
            else if (mode == 2)
            {
                msg[i] = (msg[i] - base - key + 26) % 26 + base;
            }
        }
    }
}

int main()
{
    int mode, key;
    char message[50];

    while (1)
    {
        scanf("%d %d", &mode, &key);

        if (mode == 0)
        {
            break;
        }

        getchar();
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0';

        switch (mode)
        {
        case 1:
            cipher(1, key, message);
            printf("%s\n", message);
            break;
        case 2:
            cipher(2, key, message);
            printf("%s\n", message);
            break;
        default:
            printf("Wrong Input. Input Again.\n");
        }
    }
}