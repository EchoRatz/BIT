#include <stdio.h>

void largestNum(int n)
{

    int i;

    int count[10] = {0};

    while (n > 0)
    {
        int digit = n % 10;
        count[digit]++;
        n /= 10;
    }

    int result = 0;
    for (i = 9; i >= 0; i--)
    {
        while (count[i] > 0)
        {

            result = result * 10 + i;
            count[i]--;
        }
    }
    printf("%d\n", result);
}

int main()
{

    int n, result;

    scanf("%d", &n);

    if (n > 0)
    {
        largestNum(n);
    }
    else
    {
        printf("Error!\n");
    }
}
