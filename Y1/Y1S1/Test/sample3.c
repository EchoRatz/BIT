#include <stdio.h>
#include <string.h>

int main()
{
    char lottery[10];
    int i;
    int havefour = 0;

    scanf("%s", lottery);

    if (strlen(lottery) != 5)
    {
        printf("invalid input\n");
        return 0;
    }

    for (i = 0; i < 5; i++)
    {
        if (lottery[i] < '0' || lottery[i] > '9')
        {
            printf("invalid input\n");
            return 0;
        }
        if (lottery[i] == '4')
        {
            havefour = 1;
        }
    }

    if (lottery[0] == lottery[1] && lottery[1] == lottery[2] && lottery[2] == lottery[3] && lottery[3] == lottery[4])
    {
        printf("most lucky\n");
    }
    else if ((lottery[0] == lottery[1] && lottery[1] == lottery[2] && lottery[2] == lottery[3]) ||
             (lottery[1] == lottery[2] && lottery[2] == lottery[3] && lottery[3] == lottery[4]))
    {
        printf("very lucky\n");
    }
    else if ((lottery[0] == lottery[1] && lottery[1] == lottery[2]) ||
             (lottery[1] == lottery[2] && lottery[2] == lottery[3]) ||
             (lottery[2] == lottery[3] && lottery[3] == lottery[4]))
    {
        printf("lucky\n");
    }
    else if (havefour == 1)
    {
        printf("unlucky\n");
    }
    else
    {
        printf("just fine\n");
    }
}