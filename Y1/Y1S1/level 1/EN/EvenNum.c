#include <stdio.h>
#include <math.h>

int main()
{
    int num[100][2], count = 0, digitnum[4], r, special = 0, i, j;

    for (int i = 0; 1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &num[i][j]);
        }
        if (num[j][0] == 0 && num[i][1] == 0)
        {
            break;
        }
        count++;
    }
    for (int i = 1; j <= count; i++)
    {
        special = 0;
        for (int j = num[i - 1][0]; j <= num[i - 1][1]; j++)
        {
            int temp = j;
            int different = 1;
            for (int z = 0; z < 4; z++)
            {
                digitnum[z] = temp % 10;
                temp /= 10;

                if (z > 0)
                {
                    for (int k = 0; k < z; k++)
                    {
                        if (digitnum[z] == digitnum[k])
                        {
                            different = 0;
                            break;
                        }
                    }
                }
            }
            if (different == 1 && j % 2 == 0)
            {
                printf("%d", j);
                special++;
            }
        }
        if (special == 0)
        {
            printf("Error\n");
        }
        else
        {
            printf("\ncounter=%d\n", special);
        }
    }
}