#include <stdio.h>

double calculate(int n, int current)
{
    if (current > n)
    {
        return 0.0;
    }

    if (current % 2 == 0)
    {
        return 1.0 / current + calculate(n, current + 1);
    }
    else
    {
        return -1.0 / current + calculate(n, current + 1);
    }
}

int main()
{

    int n;
    scanf("%d", &n);

    double sum = 1 + calculate(n, 2);

    if (sum == 1)
    {
        printf("%.0f\n", sum);
    }
    else
    {
        printf("%6f\n", sum);
    }
}