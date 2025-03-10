#include <stdio.h>

void newbase(int decimal, int base)
{
    if (base < 2 || base > 16)
    {
        printf("Error!\n");
        return;
    }

    char result[50];
    int i, index = 0;

    while (decimal > 0)
    {
        int remainder = decimal % base;

        result[index++] = (remainder < 10) ? (char)(remainder + '0') : (char)(remainder - 10 + 'A');

        decimal /= base;
    }

    for (int i = index - 1; i >= 0; i--)
    {
        printf("%c", result[i]);
    }

    printf("\n");
}

int main()
{
    int decimal, base;
    scanf("%d", &decimal);
    scanf("%d", &base);

    printf("%d in %d based system is ", decimal, base);

    newbase(decimal, base);
}