#include <stdio.h>

void sorting(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int i, j, n, m;

    scanf("%d %d", &n, &m);

    int arr[n + 1];

    for (i = 0; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    sorting(arr, n);

    for (i = 0; i < n; i++)
    {
        if (m > arr[i])
        {
            break;
        }
    }

    for (j = n; j > i; j--)
    {
        arr[j] = arr[j - 1];
    }
    arr[i] = m;

    for (i = 0; i <= n; i++)
    {
        printf("%d", arr[i]);
        if (i != n)
        {
            printf(" ");
        }
    }
    printf("\n");
}