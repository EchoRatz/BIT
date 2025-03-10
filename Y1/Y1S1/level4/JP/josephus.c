#include <stdio.h>

int josephus(int n, int k)
{
    if (n == 1)
    {
        return 0;
    }
    else
    {
        return (josephus(n - 1, k) + k) % n;
    }
}

int main()
{

    int n, k;

    scanf("%d %d", &n, &k);

    int survivor = josephus(n, k + 1) + 1;

    printf("The lucky person is no:%d\n", survivor);
}