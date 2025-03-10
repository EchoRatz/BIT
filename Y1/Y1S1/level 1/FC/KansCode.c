#include <stdio.h>
int main()
{

    int i, j;

    float plan[3][2];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            scanf("%f", &plan[i][j]);
        }
    }
    for (i = 0; i < 3; i++)
    {
        if (plan[i][0] == 1)
        {
            printf("The Centigrade is %.2f\n", (plan[i][1] - 32) * 5.0 / 9.0);
        }
        else if (plan[i][0] == 2)
        {
            printf("The Fahrenheit is %.2f\n", (plan[i][1] * 1.8) + 32);
        }
        else
        {
            printf("Wrong input!\n");
        }
    }
}