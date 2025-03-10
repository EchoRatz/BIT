#include <stdio.h>
int main()
{

    int a, b, sum = 0, i;
    while (1)
    {
        scanf("%d %d", &a, &b);
        // printf("%d,%d",a,b);
        if (a != 0 && b != 0)
        {

            for (i = a; i <= b; i++)
            {
                sum += i;
            }
            printf("%d\n", sum);
            sum = 0;
        }
        else
            break;
    }
}