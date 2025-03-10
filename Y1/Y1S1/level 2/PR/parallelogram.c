#include <stdio.h>
int main()
{
    int num, line = 0;

    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < i && i > 0; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < num; k++)
        {
            printf("*");
        }
        printf("\n");
    }

    if (num < 0)
    {
        printf("Error!\n");
    }
}