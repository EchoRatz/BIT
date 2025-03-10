#include <stdio.h>
int main()
{
    int num, counter, numperline = 0, i, j;

    scanf("%d", &num);

    for (i = 0; i <= num; i++)
    {
        counter = 0;
        for (j = i; j > 0; j--)
        {
            if (i % j == 0)
            {
                counter += 1;
            }
        }
        if (counter == 2)
        {
            if (numperline == 0)
            {
                printf("%d", i);
                numperline += 1;
            }
            else if (numperline == 5)
            {
                printf("\n%d", i);
                numperline = 1;
            }
            else
            {
                printf("\t%d", i);
                numperline += 1;
            }
        }
    }
    printf("\n");
}