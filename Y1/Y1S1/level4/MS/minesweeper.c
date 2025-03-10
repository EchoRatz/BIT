#include <stdio.h>

int main()
{
    int n, m;
    int fieldcount = 0;

    while (1)
    {
        scanf("%d %d", &n, &m);

        if (n == 0 && m == 0)
        {
            break;
        }

        fieldcount++;

        if (fieldcount != 1)
        {
            printf("\n");
        }

        char minefield[100][100];
        for (int i = 0; i < n; i++)
        {
            scanf("%s", minefield[i]);
        }

        printf("Field #%d:\n", fieldcount);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (minefield[i][j] == '*')
                {
                    printf("*");
                }
                else
                {
                    int count = 0;

                    for (int x = -1; x <= 1; x++)
                    {
                        for (int y = -1; y <= 1; y++)
                        {
                            int numi = i + x;
                            int numj = j + y;
                            if (numi >= 0 && numi < n && numj >= 0 && numj < m && minefield[numi][numj] == '*')
                            {
                                count++;
                            }
                        }
                    }
                    printf("%d", count);
                }
            }
            printf("\n");
        }
    }
    return 0;
}