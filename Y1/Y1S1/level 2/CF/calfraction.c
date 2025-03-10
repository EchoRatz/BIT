#include <stdio.h>

int findgcd(int a, int b)
{
    while ((b != 0))
    {

        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void simplify(int *Numer, int *Deno)
{
    int gcd = findgcd(*Numer, *Deno);
    *Numer /= gcd;
    *Deno /= gcd;
}

void addF(int num1, int den1, int num2, int den2)
{
    int resultNumer = (num1 * den2) + (num2 * den1);
    int resultDeno = den1 * den2;

    simplify(&resultNumer, &resultDeno);

    if (resultNumer % resultDeno == 0)
    {
        printf("%d/%d + %d/%d = %d\n", num1, den1, num2, den2, resultNumer / resultDeno);
    }
    else
    {
        printf("%d/%d + %d/%d = %d/%d\n", num1, den1, num2, den2, resultNumer, resultDeno);
    }
}

void subF(int num1, int den1, int num2, int den2)
{
    int resultNumer = (num1 * den2) - (num2 * den1);
    int resultDeno = den1 * den2;

    // simplify(&resultNumer, &resultDeno);

    if (resultNumer == 0)
    {
        printf("%d/%d - %d/%d = %d\n", num1, den1, num2, den2, resultNumer);
    }
    else
    {
        printf("%d/%d - %d/%d = %d/%d\n", num1, den1, num2, den2, resultNumer, resultDeno);
    }
}

void mulF(int num1, int den1, int num2, int den2)
{
    int resultNumer = num1 * num2;
    int resultDeno = den1 * den2;

    simplify(&resultNumer, &resultDeno);

    if (resultNumer % resultDeno == 0)
    {
        printf("%d/%d * %d/%d = %d\n", num1, den1, num2, den2, resultNumer / resultDeno);
    }
    else
    {
        printf("%d/%d * %d/%d = %d/%d\n", num1, den1, num2, den2, resultNumer, resultDeno);
    }
}

void divF(int num1, int den1, int num2, int den2)
{
    int resultNumer = num1 * den2;
    int resultDeno = den1 * num2;

    simplify(&resultNumer, &resultDeno);

    if (resultNumer % resultDeno == 0)
    {
        printf("%d/%d * %d/%d = %d\n", num1, den1, num2, den2, resultNumer / resultDeno);
    }
    else
    {
        printf("%d/%d / %d/%d = %d/%d\n", num1, den1, num2, den2, resultNumer, resultDeno);
    }
}

int main()
{
    int num1, num2, den1, den2;
    char operator;

    scanf("%d/%d %c %d/%d", &num1, &den1, &operator, & num2, &den2);

    switch (operator)
    {
    case '+':
        addF(num1, den1, num2, den2);
        break;

    case '-':
        subF(num1, den1, num2, den2);
        break;

    case '*':
        mulF(num1, den1, num2, den2);
        break;

    case '/':
        divF(num1, den1, num2, den2);
        break;

    default:
        printf("Error!\n");
    }
}