#include <stdio.h>

int main()
{
    int i, j, n;

    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        if (i == n)
        {
            for (j = 1; j <= 2 * n; j++)
            {
                printf("*");
            }
        }
        else
        {
            for (j = 1; j <= i; j++)
            {
                printf("*");
            }
        }
        printf("\n");
    }

    for (i = n - 1; i >= 1; i--)
    {
        for (j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}