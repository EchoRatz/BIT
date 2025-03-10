#include <stdio.h>

int main()
{
    int num, i, j, counter = 1;

    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            printf("%3d", counter);
            counter++;
        }
        printf("\n");
    }
}