#include <stdio.h>
int main()
{
    int num, maxPrime = 0, counter = 0, i, j;
    scanf("%d", &num);
    for (i = num; i > 0; i--)
    {
        counter = 0;
        for (j = num; j > 0; j--)
        {
            if (i % j == 0)
            {
                counter += 1;
            }
        }
        if (counter == 2)
        {
            printf("The max prime number is %d.\n", i);
            break;
        }
    }
}